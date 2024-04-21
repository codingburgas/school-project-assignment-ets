#include "encrypt.h"

QString Encrypt(const QString& plaintext, int key) {
    QString encryptedMessage = "";

    for (QChar character : plaintext) {
        if (character.isLetter()) {
            QChar base = character.isUpper() ? 'A' : 'a';
            encryptedMessage += QChar((character.toLatin1() - base.toLatin1() + key) % 26 + base.toLatin1());
        } else {
            encryptedMessage += character;
        }
    }

    return encryptedMessage;
}

QString Decrypt(const QString& ciphertext, int key) {
    QString decryptedMessage = "";

    for (QChar character : ciphertext) {
        if (character.isLetter()) {
            QChar base = character.isUpper() ? 'A' : 'a';
            decryptedMessage += QChar((character.toLatin1() - base.toLatin1() - key + 26) % 26 + base.toLatin1());
        } else {
            decryptedMessage += character;
        }
    }

    return decryptedMessage;
}