// contactlist.h
#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include "contact.h"
#include <QList>

class ContactList {
public:
    void addContact(const Contact& contact);
    void removeContact(int index);
    QList<Contact> searchByName(const QString& name) const;
    const QList<Contact>& getAllContacts() const;

private:
    QList<Contact> contacts;
};

#endif // CONTACTLIST_H
