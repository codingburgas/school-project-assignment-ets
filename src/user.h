#ifndef USER_H
#define USER_H
#include <QString>

class User {
private:
    QString username, email;
    int id;
public:
    QString& GetUsername();
    QString& GetEmail();
    int& GetId();
    User();
    User(const QString& username, const QString& email, const int& id);
};


#endif // USER_H
