import sqlite3
import queries

connection = sqlite3.connect("customer_tracking_system.db")
connection.execute("PRAGMA foreign_keys = ON")

def create_tables():
    with connection:
        connection.execute(queries.CREATE_CUSTOMER_TABLE)
        connection.execute(queries.CREATE_LOCATION_TABLE)
        connection.execute(queries.CREATE_SERVICE_TABLE)
        connection.execute(queries.CREATE_EQUIPMENT_TABLE)
        connection.execute(queries.CREATE_BILLING_TABLE)

#Adding / Inserting
def add_new_customer(customer_name, phone_number, street_address, city, state, zip_code):
    with connection:
        connection.execute(queries.INSERT_NEW_CUSTOMER, (customer_name, phone_number))
        connection.execute(queries.INSERT_NEW_LOCATION, (customer_name, street_address, city, state, zip_code))

def add_service_equipment(item_type, item_name, item_cost, credit_card_number, customer_name):
    with connection:
        connection.execute(queries.INSERT_SERVICE_EQUIPMENT, (item_type, item_name, item_cost, credit_card_number, customer_name))

#Viewing / Selects
def view_customer_payments(customer_name="", street_address="", city="", state="", zip_code=""):
    cursor = connection.cursor()
    cursor.execute(queries.SELECT_CUSTOMER_LAST_PAYMENT,(f"%{customer_name}%", f"%{street_address}%",
                                                         f"%{city}%", f"%{state}%", f"%{zip_code}%"))
    return cursor.fetchone()

def view_late_payments():
    cursor = connection.cursor()
    cursor.execute(queries.SELECT_CUSTOMER_LATE_PAYMENT)
    return cursor

def view_services():
    cursor = connection.cursor()
    cursor.execute(queries.SELECT_SERVICES)
    return cursor

def view_equipment():
    cursor = connection.cursor()
    cursor.execute(queries.SELECT_EQUIPMENT)
    return cursor

#Deletes
def delete_customer(customer_name):
    with connection:
        connection.execute(queries.DELETE_CUSTOMER, (customer_name,))

def delete_service_equipment(item_name, customer_name):
    with connection:
        connection.execute(queries.DELETE_SERVICE_EQUIPMENT, (item_name,customer_name))

#Update
def update_last_payment_date(new_payment_date, customer_name):
    with connection:
        connection.execute(queries.UPDATE_LAST_PAYMENT, (new_payment_date, customer_name))

def update_service_cost(service_name, new_service_cost):
    with connection:
        connection.execute(queries.UPDATE_SERVICE_COST, (service_name, new_service_cost))

def update_equipment_cost(equipment_name, new_equipment_cost):
    with connection:
        connection.execute(queries.UPDATE_EQUIPMENT_COST, (equipment_name, new_equipment_cost))

def update_billing_cost(new_billing_cost, item_type, item_name):
    with connection:
        connection.execute(queries.UPDATE_BILLING_COST, (new_billing_cost, item_type, item_name))
        connection.commit()

#Checks
def customer_name_exists(name):
    cursor = connection.cursor()
    cursor.execute(queries.CHECK_IF_CUSTOMER_EXISTS, (name,))

    if len(cursor.fetchall()) == 0:
        return False
    else:
        return True

def service_exists(service_name):
    cursor = connection.cursor()
    cursor.execute(queries.CHECK_IF_SERVICE_EXISTS, (service_name,))

    if len(cursor.fetchall()) == 0:
        return False
    else:
        return True

def equipment_exists(equipment_name):
    cursor = connection.cursor()
    cursor.execute(queries.CHECK_IF_EQUIPMENT_EXISTS, (equipment_name,))

    if len(cursor.fetchall()) == 0:
        return False
    else:
        return True

def billing_exists(item_name, customer_name):
    cursor = connection.cursor()
    cursor.execute(queries.CHECK_IF_BILLING_EXISTS, (customer_name, item_name))

    if len(cursor.fetchall()) == 0:
        return False
    else:
        return True