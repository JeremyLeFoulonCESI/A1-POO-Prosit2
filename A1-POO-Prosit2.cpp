#include <iostream>
#include "Services.Decrypter.hpp"
#include "Services.Encrypter.hpp"
#include "HMI.Terminal.hpp"


Services::FileEncryptionOperation* make_operation(bool does_encrypt, const char* src_path, const char* dst_path, uint8_t encrypt_level, uint8_t encrypt_key) {
    if (does_encrypt)
        return new Services::Encrypter(does_encrypt, src_path, dst_path, encrypt_level, encrypt_key);
    return new Services::Decrypter(does_encrypt, src_path, dst_path, encrypt_level, encrypt_key);
}


int main()
{
    HMI::Terminal.writeLine("Souhaitez-vous dechiffrer (1) ou chiffrer (2) un fichier ? ");
    int operating_type = HMI::Terminal.readInt(1, 2);

    const char* op_name;
    if (operating_type - 1)
        op_name = "chiffrement";
    else
        op_name = "dechiffrement";

    HMI::Terminal.writeLine("Entrer le chemin d'acces du fichier source.");
    const char* src_path = HMI::Terminal.readLine();

    HMI::Terminal.writeLine("Entrer le type de chiffrement.");
    HMI::Terminal.writeLine("Cesar: 1");
    HMI::Terminal.writeLine("XOR: 2");
    HMI::Terminal.writeLine("Cesar et XOR: 3");
    uint8_t encrypt_level = HMI::Terminal.readInt(1, 3);

    HMI::Terminal.writeLine("Entrer le chemin d'acces du fichier de destination.");
    const char* dst_path = HMI::Terminal.readLine();

    HMI::Terminal.writeLine("Entrer la cle de chiffrement.");
    uint8_t encrypt_key = HMI::Terminal.readInt(0, 255);

    HMI::Terminal.write("Voici un recapitulatif des informations pour le ");
    HMI::Terminal.write(op_name);
    HMI::Terminal.writeLine(":");
    HMI::Terminal.write("Fichier source: ");
    HMI::Terminal.writeLine(src_path);

    HMI::Terminal.write("Type de chiffrement: ");
    HMI::Terminal.writeLine(encrypt_level);

    HMI::Terminal.write("Fichier de destination: ");
    HMI::Terminal.writeLine(dst_path);

    HMI::Terminal.write("Cle de chiffrement: ");
    HMI::Terminal.writeLine(encrypt_key);

    HMI::Terminal.writeLine("Notes:");
    HMI::Terminal.write("Le ");
    HMI::Terminal.write(op_name);
    HMI::Terminal.writeLine(" d'un fichier avec des informations incorrectes");
    HMI::Terminal.writeLine("risque de produire un fichier de destination corrompu.");
    HMI::Terminal.writeLine("Assurez-vous que ces informations sont correctes.");
    HMI::Terminal.writeLine("Si le fichier de destination n'existe pas, il sera cree a");
    HMI::Terminal.writeLine("l'emplacement indique.");

    HMI::Terminal.writeLine();
    HMI::Terminal.write("Appuyer sur la touche entree pour commencer le ");
    HMI::Terminal.write(op_name);
    HMI::Terminal.writeLine(".");
    HMI::Terminal.pause();
    
    Services::FileEncryptionOperation* operation = make_operation(operating_type - 1, src_path, dst_path, encrypt_level, encrypt_key);
    if (!operation->isValid()) {
        HMI::Terminal.write("Une ou plusieurs erreurs se sont produites, fin du ");
        HMI::Terminal.write(op_name);
        HMI::Terminal.writeLine(".");
        goto end;
    }

    operation->transform();

    HMI::Terminal.write("Le ");
    HMI::Terminal.write(op_name);
    HMI::Terminal.writeLine(" a ete effectue avec succes.");
    HMI::Terminal.write("Fin du ");
    HMI::Terminal.write(op_name);
    HMI::Terminal.writeLine(".");

end:
    delete operation;
    delete src_path;
    delete dst_path;
}
