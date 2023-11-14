#include <iostream>
#include "Services.Decrypter.hpp"
#include "Services.Encrypter.hpp"
#include "HMI.Terminal.hpp"


int decrypt() {
    int res = 0;

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

    HMI::Terminal.writeLine("Voici un recapitulatif des informations pour le dechiffrement:");
    HMI::Terminal.write("Fichier source: ");
    HMI::Terminal.writeLine(src_path);

    HMI::Terminal.write("Type de chiffement: ");
    HMI::Terminal.writeLine(encrypt_level);

    HMI::Terminal.write("Fichier de destination: ");
    HMI::Terminal.writeLine(dst_path);

    HMI::Terminal.write("Cle de chiffrement: ");
    HMI::Terminal.writeLine(encrypt_key);

    HMI::Terminal.writeLine("Notes:");
    HMI::Terminal.writeLine("Le dechiffrement d'un fichier avec des informations incorrectes");
    HMI::Terminal.writeLine("risque de produire un fichier de destination corrompu.");
    HMI::Terminal.writeLine("Si le fichier de destination n'existe pas, il sera cree a");
    HMI::Terminal.writeLine("l'emplacement indique.");

    HMI::Terminal.writeLine();
    HMI::Terminal.writeLine("Appuyer sur la touche entree pour commencer le dechiffrement.");
    HMI::Terminal.pause();

    Services::Decrypter decrypter(src_path, dst_path, encrypt_level, encrypt_key);
    if (!decrypter.isValid()) {
        HMI::Terminal.writeLine("Une ou plusieurs erreurs se sont produites, fin du dechiffrement.");
        res = 1;
        goto end;
    }

    decrypter.decrypt();

    HMI::Terminal.writeLine("Le dechiffrement a ete effectue avec succes.");
    HMI::Terminal.writeLine("Fin du dechiffrement.");

end:
    delete src_path;
    delete dst_path;
    return res;
}


int encrypt() {
    int res = 0;

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

    HMI::Terminal.writeLine("Voici un recapitulatif des informations pour le chiffrement:");
    HMI::Terminal.write("Fichier source: ");
    HMI::Terminal.writeLine(src_path);

    HMI::Terminal.write("Type de chiffrement: ");
    HMI::Terminal.writeLine(encrypt_level);

    HMI::Terminal.write("Fichier de destination: ");
    HMI::Terminal.writeLine(dst_path);

    HMI::Terminal.write("Cle de chiffrement: ");
    HMI::Terminal.writeLine(encrypt_key);

    HMI::Terminal.writeLine("Notes:");
    HMI::Terminal.writeLine("Le chiffrement d'un fichier avec des informations incorrectes");
    HMI::Terminal.writeLine("risque de produire un fichier de destination corrompu.");
    HMI::Terminal.writeLine("Si le fichier de destination n'existe pas, il sera cree a");
    HMI::Terminal.writeLine("l'emplacement indique.");

    HMI::Terminal.writeLine();
    HMI::Terminal.writeLine("Appuyer sur la touche entree pour commencer le chiffrement.");
    HMI::Terminal.pause();

    Services::Encrypter encrypter(src_path, dst_path, encrypt_level, encrypt_key);
    if (!encrypter.isValid()) {
        HMI::Terminal.writeLine("Une ou plusieurs erreurs se sont produites, fin du chiffrement.");
        res = 1;
        goto end;
    }

    encrypter.encrypt();

    HMI::Terminal.writeLine("Le chiffrement a ete effectue avec succes.");
    HMI::Terminal.writeLine("Fin du chiffrement.");

end:
    delete src_path;
    delete dst_path;
    return res;
}


int main()
{
    HMI::Terminal.writeLine("Souhaitez-vous dechiffrer (1) ou chiffrer (2) un fichier ? ");
    int operating_type = HMI::Terminal.readInt(1, 2);
    
    if (operating_type == 1) {
        return decrypt();
    }
    return encrypt();
}
