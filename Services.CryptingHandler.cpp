#include "Services.CryptingHandler.hpp"
#include "HMI.Terminal.hpp"
#include <iostream>


namespace Services {

	CryptingHandler::CryptingHandler(const char* src_filename, const char* dst_filename, uint8_t encryptionKind, uint8_t key) {
		if (!Components::File::exists(src_filename)) {
			this->src = nullptr;
		}
		else {
			this->src = Components::File::open(src_filename);
		}
		if (!Components::File::exists(dst_filename)) {
			this->dst = Components::File::create(dst_filename);
		}
		else {
			this->dst = Components::File::open(dst_filename);
		}
		if (!this->src) {
			HMI::Terminal.write("Erreur: Impossible de trouver le fichier source '");
			HMI::Terminal.write(src_filename);
			HMI::Terminal.writeLine("'.");
		}
		if (!this->dst) {
			HMI::Terminal.write("Erreur: Le format du fichier de destination '");
			HMI::Terminal.write(src_filename);
			HMI::Terminal.writeLine("' est invalide.");
		}
		switch (encryptionKind) {
		case 1:
			this->encryption_kind = Components::EncryptionKind::CESAR;
			break;
		case 2:
			this->encryption_kind = Components::EncryptionKind::XOR;
			break;
		case 3:
			this->encryption_kind = Components::EncryptionKind::CESAR_XOR;
			break;
		default:
			HMI::Terminal.write("Erreur: type de chiffrage '");
			HMI::Terminal.write(encryptionKind);
			HMI::Terminal.writeLine("' invalide.");
			this->encryption_kind = Components::EncryptionKind::INVALID;
		}
		this->key = key;
	}

	uint8_t CryptingHandler::getKey() {
		return this->key;
	}
	const char* CryptingHandler::getSource() {
		return this->src->getFilePath();
	}
	const char* CryptingHandler::getDestination() {
		return this->dst->getFilePath();
	}
	bool CryptingHandler::isValid() {
		if (this->encryption_kind == Components::EncryptionKind::INVALID)
			return 0;
		if (this->src == nullptr)
			return 0;
		return this->src->isValid() && this->dst->isValid();
	}
	CryptingHandler::~CryptingHandler() {
		if (this->src) {
			delete this->src;
			this->src = nullptr;
		}
		if (this->dst) {
			delete this->dst;
			this->dst = nullptr;
		}
	}
}

