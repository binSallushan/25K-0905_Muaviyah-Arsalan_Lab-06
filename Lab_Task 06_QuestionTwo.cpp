#include <iostream>
#include <string>
using namespace std;

class Message {
private:
    string text;

public:
    void setText(string t) {
        text = t;
    }

    string getText() const {
        return text;
    }

    virtual string toString() const {
        return text;
    }
};

class SMS : public Message {
private:
    string recipientContactNo;

public:
    void setRecipientContactNo(string num) {
        recipientContactNo = num;
    }

    string getRecipientContactNo() const {
        return recipientContactNo;
    }

    string toString() const override {
        return "SMS to: " + recipientContactNo + "\nMessage: " + getText();
    }
};

class Email : public Message {
private:
    string sender;
    string receiver;
    string subject;

public:
    void setSender(string s) {
        sender = s;
    }

    void setReceiver(string r) {
        receiver = r;
    }

    void setSubject(string s) {
        subject = s;
    }

    string getSender() const {
        return sender;
    }

    string getReceiver() const {
        return receiver;
    }

    string getSubject() const {
        return subject;
    }

    string toString() const override {
        return "From: " + sender +
               "\nTo: " + receiver +
               "\nSubject: " + subject +
               "\nMessage: " + getText();
    }
};

bool ContainsKeyword(const Message& messageObject, const string& keyword) {
    string text = messageObject.getText();
    return text.find(keyword) != string::npos;
}

string encodeMessage(string message) {

    for (int i = 0; i < message.length(); i++) {

        if (message[i] >= 'A' && message[i] <= 'Y')
            message[i]++;

        else if (message[i] == 'Z')
            message[i] = 'A';

        else if (message[i] >= 'a' && message[i] <= 'y')
            message[i]++;

        else if (message[i] == 'z')
            message[i] = 'a';
    }

    return message;
}

int main() {

    SMS sms;
    sms.setRecipientContactNo("03001234567");
    sms.setText("Hello this is Java");

    cout << sms.toString() << endl;

    Email email;
    email.setSender("alice@gmail.com");
    email.setReceiver("bob@gmail.com");
    email.setSubject("Meeting");
    email.setText("This is Java class");

    cout << "\n" << email.toString() << endl;

    string keyword = "Java";

    if (ContainsKeyword(email, keyword))
        cout << "\nKeyword found in email." << endl;
    else
        cout << "\nKeyword not found." << endl;

    string encoded = encodeMessage("This is Java");
    cout << "\nEncoded Message: " << encoded << endl;

    return 0;
}