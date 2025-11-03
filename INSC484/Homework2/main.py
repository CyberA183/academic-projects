import database
import datetime

welcome = "Welcome to NovaLink's Customer Tracking System!"

menu = """\nPlease select one of the following options:
1. Add New Customer
2. Remove Customer
3. Customer Payment Lookup
4. View Late Payments
5. Update Last Payment
6. Add Service or Equipment
7. Remove Service or Equipment
8. Change Cost of Service or Equipment
9. Exit

Your selection: """

def normalize(text):
    return text.lower().strip()

#Prompts for selections
def prompt_add_new_customer():
    customer_name = input("Enter Customer Name: ")
    customer_phone_number = input("Enter Customer Phone Number: ")

    print("-------Location Information-------")
    street_address = input("Enter Street Address: ")
    city = input("Enter City: ")
    state = input("Enter State: ")
    zip_code = input("Enter Zip Code: ")

    if not database.customer_name_exists(customer_name):
        return customer_name, customer_phone_number, street_address, city, state, zip_code
    else:
        print("The customer already exists in the system.")
        return None

def prompt_remove_customer():
    customer_to_remove = input("Enter Customer Name: ")

    if not database.customer_name_exists(customer_to_remove):
        print("The customer does not exist in the system.")
        return None
    else:
        return customer_to_remove

def view_customer_payments():
    print("Choose to search by: name, address, city, state, zipcode.")
    search_choice = normalize(input("Enter Search Choice: "))
    search_input = input("Enter Search Input: ")

    if search_choice == "name":
        customer_name, last_payment_date = database.view_customer_payments(customer_name=search_input)
    elif search_choice == "address":
        customer_name, last_payment_date = database.view_customer_payments(street_address=search_input)
    elif search_choice == "city":
        customer_name, last_payment_date = database.view_customer_payments(city=search_input)
    elif search_choice == "state":
        customer_name, last_payment_date = database.view_customer_payments(state=search_input)
    elif search_choice == "zipcode":
        customer_name, last_payment_date = database.view_customer_payments(zip_code=search_input)
    else:
        print("Invalid input.")

    return customer_name, last_payment_date

def prompt_update_last_payment():
    customer_name = input("Enter Customer Name: ")
    payment_date = input("Enter Payment Date (YYYY-MM-DD): ")

    if database.customer_name_exists(customer_name):
        try:
            date_object = datetime.datetime.strptime(payment_date, "%Y-%m-%d")
            payment_timestamp = date_object.timestamp()
            return customer_name, payment_timestamp
        except ValueError:
            print("Payment Date must be in YYYY-MM-DD format.")
    else:
        print("The customer does not exist in the system.")
        return None

def prompt_add_service_equipment():
    services = database.view_services()
    equipment = database.view_equipment()

    print("Services Provided", services)
    print("Equipment Provided", equipment)

    customer_name = input("Enter Customer Name: ")
    item_name = input("Enter Item Name: ")
    item_type = normalize(input("Enter Item Type: "))
    item_cost = int(input("Enter Item Cost: "))
    credit_card_number = input("Enter Credit Card Number: ")

    if database.customer_name_exists(customer_name):
        if item_type == "service":
            if database.service_exists(item_name):
                return item_type, item_name, item_cost, credit_card_number, customer_name
            else:
                print("This service does not exist in the system.")
                return None
        elif item_type == "equipment":
            if database.equipment_exists(item_name):
                return item_type, item_name, item_cost, credit_card_number, customer_name
            else:
                print("This equipment does not exist in the system.")
                return None
        else:
            print("Invalid item type. Item must be service or equipment.")
            return None
    else:
        print("The customer does not exist in the system.")
        return None

def prompt_remove_service_equipment():
    print("Please enter the item name and the customer you wish to remove it from.")
    customer_name = input("Enter Customer Name: ")
    item_name = input("Enter Item Name: ")

    if database.customer_name_exists(customer_name):
        if database.billing_exists(item_name, customer_name):
            return item_name, customer_name
        else:
            print("This item belonging to this customer does not exist in the system.")
            return None
    else:
        print("The customer does not exist in the system.")
        return None

def prompt_update_cost_service_equipment():
    services = database.view_services()
    equipment = database.view_equipment()

    print("Services Provided", services)
    print("Equipment Provided", equipment)

    item_type = normalize(input("Item to Update (service or equipment): "))
    item_name = input("Enter Item Name: ")
    new_item_cost = int(input("Enter New Item Cost: "))

    if item_type == "service":
        if database.service_exists(item_name):
            return item_name, new_item_cost
        else:
            print("This service does not exist in the system.")
            return None
    elif item_type == "equipment":
        if database.equipment_exists(item_name):
            return item_name, new_item_cost
        else:
            print("This equipment does not exist in the system.")
            return None
    else:
        print("Invalid item type. Item must be service or equipment.")
        return None

#Prints
def print_late_payments():
    customer_name = database.view_late_payments()
    print("------ Late Payments ------")
    print(f"Customer Name: {customer_name}")

print(welcome)
database.create_tables()

while (user_input := input(menu)) != "9":
    if user_input == "1":
        name, phone_number, street_address, city, state, zip_code = prompt_add_new_customer()
        database.add_new_customer(name, phone_number, street_address, city, state, zip_code)
    elif user_input == "2":
        name = prompt_remove_customer()
        database.delete_customer(name)
    elif user_input == "3":
        name, last_payment = view_customer_payments()
        print(f"\nCustomer Name: {name}, Last Payment Date: {last_payment}")
    elif user_input == "4":
        print_late_payments()
    elif user_input == "5":
        name, payment_date = prompt_update_last_payment()
        database.update_last_payment_date(name, payment_date)
    elif user_input == "6":
        item_type, item_name, item_cost, credit_card_number, name = prompt_add_service_equipment()
        database.add_service_equipment(item_type, item_name, item_cost, credit_card_number, name)
    elif user_input == "7":
        name, item_name = prompt_remove_service_equipment()
        database.delete_service_equipment(name, item_name)
    elif user_input == "8":
        item_type, item_name, item_cost = prompt_update_cost_service_equipment()
        if item_type == "service":
            database.update_service_cost(item_name, item_cost)
            database.update_billing_cost(item_cost, item_type, item_name)
        else:
            database.update_equipment_cost(item_name, item_cost)
            database.update_billing_cost(item_cost, item_type, item_name)
    else:
        print("Invalid input. Please try again.")
