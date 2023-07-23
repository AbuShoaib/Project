#include <iostream>
#include <string>
#include <vector>

class Donor {
public:
    std::string name;
    std::string blood_group;
    int age;
    std::string gender;
    std::string contact_number;
    int roll;
    std::string department;
    std::string last_donation_date;

    Donor(const std::string& name, const std::string& blood_group, int age, const std::string& gender, const std::string& contact_number, int roll, const std::string& department, const std::string& last_donation_date)
        : name(name), blood_group(blood_group), age(age), gender(gender), contact_number(contact_number), roll(roll), department(department), last_donation_date(last_donation_date) {}
};

class BloodBank {
private:
    std::vector<Donor> donors;

public:
    void addDonor(const Donor& donor) {
        donors.push_back(donor);
        std::cout << "Donor information added successfully!\n";
    }

    void viewAllDonors() {
        if (donors.empty()) {
            std::cout << "No donors found in the blood bank.\n";
        } else {
            std::cout << "\nDonor information:\n";
            for (size_t i = 0; i < donors.size(); ++i) {
                std::cout << "-------------------------\n";
                std::cout << "Donor " << i + 1 << ":\n";
                std::cout << "Name: " << donors[i].name << "\n";
                std::cout << "Blood Group: " << donors[i].blood_group << "\n";
                std::cout << "Age: " << donors[i].age << "\n";
                std::cout << "Gender: " << donors[i].gender << "\n";
                std::cout << "Contact: " << donors[i].contact_number << "\n";
                std::cout << "Roll: " << donors[i].roll << "\n";
                std::cout << "Department: " << donors[i].department << "\n";
                std::cout << "Last Donation Date: " << donors[i].last_donation_date << "\n";
            }
            std::cout << "-------------------------\n";
        }
    }

    void searchDonor(const std::string& blood_group) {
        std::vector<Donor> matchingDonors;
        for (const auto& donor : donors) {
            if (donor.blood_group == blood_group) {
                matchingDonors.push_back(donor);
            }
        }

        if (matchingDonors.empty()) {
            std::cout << "No donors with blood group " << blood_group << " found.\n";
        } else {
            std::cout << "\nMatching donors with blood group " << blood_group << ":\n";
            for (size_t i = 0; i < matchingDonors.size(); ++i) {
                std::cout << "-------------------------\n";
                std::cout << "Donor " << i + 1 << ":\n";
                std::cout << "Name: " << matchingDonors[i].name << "\n";
                std::cout << "Age: " << matchingDonors[i].age << "\n";
                std::cout << "Gender: " << matchingDonors[i].gender << "\n";
                std::cout << "Contact: " << matchingDonors[i].contact_number << "\n";
                std::cout << "Roll: " << matchingDonors[i].roll << "\n";
                std::cout << "Department: " << matchingDonors[i].department << "\n";
                std::cout << "Last Donation Date: " << matchingDonors[i].last_donation_date << "\n";
            }
            std::cout << "-------------------------\n";
        }
    }
};

void displayMenu() {
    std::cout << "\n---------------------------------\n";
    std::cout << "   Blood Bank Management System   \n";
    std::cout << "---------------------------------\n";
    std::cout << "1. Add Donor Information\n";
    std::cout << "2. View All Donors\n";
    std::cout << "3. Search Donor by Blood Group\n";
    std::cout << "4. Exit\n";
    std::cout << "---------------------------------\n";
    std::cout << "Enter your choice (1/2/3/4): ";
}

int main() {
    BloodBank bloodBank;

    while (true) {
        displayMenu();

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::string name, blood_group, gender, contact_number, department, last_donation_date;
            int age, roll;

            std::cout << "Enter donor's name: ";
            std::cin.ignore();
            std::getline(std::cin, name);

            std::cout << "Enter donor's blood group: ";
            std::getline(std::cin, blood_group);

            std::cout << "Enter donor's age: ";
            std::cin >> age;

            std::cout << "Enter donor's gender: ";
            std::cin.ignore();
            std::getline(std::cin, gender);

            std::cout << "Enter donor's contact number: ";
            std::getline(std::cin, contact_number);

            std::cout << "Enter donor's roll: ";
            std::cin >> roll;

            std::cout << "Enter donor's department: ";
            std::cin.ignore();
            std::getline(std::cin, department);

            std::cout << "Enter last donation date (DD/MM/YYYY): ";
            std::getline(std::cin, last_donation_date);

            Donor donor(name, blood_group, age, gender, contact_number, roll, department, last_donation_date);
            bloodBank.addDonor(donor);

        } else if (choice == 2) {
            bloodBank.viewAllDonors();

        } else if (choice == 3) {
            std::string blood_group;
            std::cout << "Enter the blood group to search for: ";
            std::cin.ignore();
            std::getline(std::cin, blood_group);
            bloodBank.searchDonor(blood_group);

        } else if (choice == 4) {
            std::cout << "Thank you for using the Blood Bank Management System!\n";
            break;
        } else {
            std::cout << "Invalid choice. Please select a valid option (1/2/3/4).\n";
        }
    }

    return 0;
}
