// contactlist.cpp
#include "contactlist.h"

void ContactList::addContact(const Contact& contact) {
    contacts.append(contact);
}

void ContactList::removeContact(int index) {
    if (index >= 0 && index < contacts.size())
        contacts.removeAt(index);
}

QList<Contact> ContactList::searchByName(const QString& name) const {
    QList<Contact> results;
    for (const Contact& c : contacts) {
        if (c.getName().contains(name, Qt::CaseInsensitive))
            results.append(c);
    }
    return results;
}

const QList<Contact>& ContactList::getAllContacts() const {
    return contacts;
}
