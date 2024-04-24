#include "user.h"
//Initializing the user
QString& User::GetUsername() {
    return username;
}
QString& User::GetEmail() {
    return email;
}
int& User::GetId() {
    return id;
}

User::User() = default;
User::User(const QString& username, const QString& email, const int& id):
    username(username), email(email), id(id) {}
