#ifndef ENCRYPT_H
#define ENCRYPT_H
#include <QString>

QString Encrypt(const QString& plaintext, int key=5);

QString Decrypt(const QString& ciphertext, int key=5);

#endif // ENCRYPT_H
