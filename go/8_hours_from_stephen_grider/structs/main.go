package main

import "fmt"

type contactInfo struct {
	email   []string
	zipCode int
}

type person struct {
	firstName string
	lastName  string
	contactInfo
}

func main() {
	jim := person{
		firstName: "Jim",
		lastName:  "Party",
		contactInfo: contactInfo{
			email:   []string{"jim@gmail.com", "jimmy@gmail.com"},
			zipCode: 94000,
		},
	}
	jim.changeName("Hahaha")
	jim.print()
}

func (pointerToPerson *person) updateName(newFirstName string) {
	(*pointerToPerson).firstName = newFirstName
}

func (p person) changeName(newFirstName string) {
	p.firstName = newFirstName
	p.contactInfo.email[0] = newFirstName
}

func (p person) print() {
	fmt.Printf("%+v", p)
}
