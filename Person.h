#pragma once
#include<iostream>
#include<string>

using namespace std;

class Person {  
    private:
        string firstName;
        string middleName;
        string lastName;
        int age = 0;
        int PersonId = 0;
    public:
    Person() {};
    Person(const Person &personCopy) {
        this -> firstName = personCopy.firstName;
        this -> middleName = personCopy.middleName;
        this -> lastName = personCopy.lastName;
        this -> age = personCopy.age;
        this -> PersonId = personCopy.PersonId;
    }
    Person(string s1 , string s2, string s3, int age, int id) {
        this -> firstName = s1;
        this -> middleName = s2;
        this -> lastName = s3;
        this -> age = age;
        this -> PersonId = id;
    }
    string GetFirstName() {
        return this -> firstName;
    }
    string GetMiddleName() {
        return this -> middleName;
    }
    string GetLastName() {
        return this -> lastName;
    }
    int GetAge() {
        return this -> age;
    }
    int GetId() {
        return this -> PersonId;
    }
    bool operator==(const Person &person) {
        if(this -> PersonId == person.PersonId){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator!=(const Person &person) { 
        return !(*this == person);
    }
};