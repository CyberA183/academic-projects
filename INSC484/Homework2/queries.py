"""
Schema for customer service tracking system:

Table Customer {
 CustomerName text [primary key]
  PhoneNumber text
}

Table Location {
  LocationID byte [primary key]
  CustomerName FK
  StreetAddress text
  City text
  State text
  ZipCode text
}

Table Service {
  ServiceID byte [primary key]
  ServiceName text
  ServiceCost decimal
}

Table Equipment {
  EquipmentID byte [primary key]
  EquipmentName text
  EquipmentCost decimal
}

Table Billing {
  BillingID byte [primary key]
  CustomerName FK
  AmountDue decimal
  CreditCardOnFile varchar(4)
  LastPaymentDate timestamp
  IsLate boolean
  ItemType text
  ItemID int
}
"""

#Create Tables
CREATE_CUSTOMER_TABLE = """CREATE TABLE IF NOT EXISTS Customer(
    CustomerName TEXT PRIMARY KEY,
    PhoneNumber TEXT);"""

CREATE_LOCATION_TABLE = """CREATE TABLE IF NOT EXISTS Location(
    LocationID INTEGER PRIMARY KEY AUTOINCREMENT,
    CustomerName TEXT,
    StreetAddress TEXT,
    City TEXT,
    State TEXT,
    ZipCode TEXT,
    FOREIGN KEY(CustomerName) REFERENCES Customer(CustomerName) ON DELETE CASCADE);"""

CREATE_SERVICE_TABLE = """CREATE TABLE IF NOT EXISTS Service(
    ServiceName TEXT PRIMARY KEY,
    ServiceCost INTEGER);"""

CREATE_EQUIPMENT_TABLE = """CREATE TABLE IF NOT EXISTS Equipment(
    EquipmentName TEXT PRIMARY KEY,
    EquipmentCost INTEGER);"""

CREATE_BILLING_TABLE = """CREATE TABLE IF NOT EXISTS Billing(
    BillingID INTEGER PRIMARY KEY AUTOINCREMENT,
    CustomerName TEXT,
    AmountDue  INTEGER,
    CreditCardOnFile TEXT,
    LastPaymentDate REAL,
    IsLate INTEGER DEFAULT 0,
    ItemType TEXT,
    ItemName TEXT,
    FOREIGN KEY(CustomerName) REFERENCES Customer(CustomerName) ON DELETE CASCADE);"""

#Insert into Tables
INSERT_NEW_CUSTOMER = """INSERT INTO Customer(CustomerName, PhoneNumber) VALUES (?, ?);"""
INSERT_NEW_LOCATION = """INSERT INTO Location(CustomerName, StreetAddress, City, State, ZipCode) 
VALUES (?, ?, ?, ?, ?);"""
INSERT_SERVICE_EQUIPMENT = """INSERT INTO Billing(ItemType, ItemName, AmountDue, CreditCardOnFile) VALUES (?, ?, ?, ?) 
WHERE CustomerName = ?;"""

#Select from Tables
SELECT_CUSTOMER_LAST_PAYMENT = """
SELECT a.CustomerName, b.LastPaymentDate
FROM Customer a
LEFT JOIN Billing b ON a.CustomerName = b.CustomerName
LEFT JOIN Location c ON a.CustomerName = c.CustomerName
WHERE a.CustomerName LIKE ? 
OR c.StreetAddress LIKE ? 
OR c.City LIKE ? 
OR c.State LIKE ? 
OR c.ZipCode LIKE ?
ORDER BY b.LastPaymentDate DESC
LIMIT 1;"""

SELECT_CUSTOMER_LATE_PAYMENT = """ SELECT CustomerName FROM Billing WHERE IsLate = 1;"""
SELECT_SERVICES = """SELECT * FROM Service"""
SELECT_EQUIPMENT = """SELECT * FROM Equipment"""

#Update Tables
UPDATE_LAST_PAYMENT = """UPDATE Billing SET LastPaymentDate = ? WHERE CustomerName = ?;"""
UPDATE_SERVICE_COST = """UPDATE Service SET ServiceCost = ? WHERE ServiceName = ?;"""
UPDATE_EQUIPMENT_COST = """UPDATE Equipment SET EquipmentCost = ? WHERE EquipmentName = ?;"""
UPDATE_BILLING_COST = """UPDATE Billing SET AmountDue = ? WHERE ItemType = ? AND ItemName = ?;"""

#Checks
CHECK_IF_CUSTOMER_EXISTS = """SELECT * FROM Customer WHERE CustomerName = ?;"""
CHECK_IF_BILLING_EXISTS = """SELECT * FROM Billing WHERE ItemName = ? AND CustomerName = ?;"""
CHECK_IF_SERVICE_EXISTS = """SELECT * FROM Service WHERE ServiceName = ?;"""
CHECK_IF_EQUIPMENT_EXISTS = """SELECT * FROM Equipment WHERE EquipmentName = ?;"""

#Delete from Tables
DELETE_CUSTOMER = """DELETE FROM Customer WHERE CustomerName=?;"""
DELETE_SERVICE_EQUIPMENT = """DELETE FROM Billing WHERE ItemName=? AND CustomerName=?;"""
