
-- Services
INSERT INTO Service VALUES ("Residential Internet (Basic)", 55);
INSERT INTO Service VALUES ("Residential Internet (Gigabit)", 90);
INSERT INTO Service VALUES ("Business Internet Plan", 250);
INSERT INTO Service VALUES ("Mobile Hotspot", 20);
INSERT INTO Service VALUES ("Basic Cable Package", 35);
INSERT INTO Service VALUES ("Expanded / HD Cable Package", 80);
INSERT INTO Service VALUES ("Premium Channels (HBO, Showtime, etc.)", 75);
INSERT INTO Service VALUES ("Sports Package", 25);
INSERT INTO Service VALUES ("Home Landline (VolP)", 30);
INSERT INTO Service VALUES ("Unlimited Long Distance", 10);
INSERT INTO Service VALUES ("International Calling Package", 40);
INSERT INTO Service VALUES ("Business VolP Line", 60);
INSERT INTO Service VALUES ("Internet + TV", 130);
INSERT INTO Service VALUES ("Internet + Phone", 80);
INSERT INTO Service VALUES ("Triple Bundle (Internet + TV + Phone)", 170);

-- Equipment
INSERT INTO Equipment VALUES ("Modem", 10);
INSERT INTO Equipment VALUES ("Wireless Router", 40);
INSERT INTO Equipment VALUES ("Fiber ONT (Optical Network Terminal)", 80);
INSERT INTO Equipment VALUES ("Ethernet Switch", 8);
INSERT INTO Equipment VALUES ("Cable TV Box", 15);
INSERT INTO Equipment VALUES ("Digital Video Recorder (DVR)", 20);
INSERT INTO Equipment VALUES ("Streaming Device (Roku/FireTV)", 6);
INSERT INTO Equipment VALUES ("Smart Hub / Gateway", 12);
INSERT INTO Equipment VALUES ("Smart Cameras", 10);
INSERT INTO Equipment VALUES ("Smart Thermostat", 6);
INSERT INTO Equipment VALUES ("Backup Power Supply (UPS)", 15);

-- Customers
INSERT INTO Customer VALUES ("Alice Johnson", "865-555-1212");
INSERT INTO Customer VALUES ("Brian Matthews", "423-555-4433");
INSERT INTO Customer VALUES ("Cynthia Lee", "931-555-8899");
INSERT INTO Customer VALUES ("David Kim", "615-555-1111");
INSERT INTO Customer VALUES ("Elena Torres", "901-555-2233");
INSERT INTO Customer VALUES ("Frank Harris", "865-555-9988");
INSERT INTO Customer VALUES ("Grace Walker", "731-555-6767");
INSERT INTO Customer VALUES ("Henry Adams", "615-555-7654");
INSERT INTO Customer VALUES ("Isabella Wright", "931-555-3322");
INSERT INTO Customer VALUES ("Jason Patel", "423-555-5555");
INSERT INTO Customer VALUES ("Karen Scott", "865-555-4040");
INSERT INTO Customer VALUES ("Liam Turner", "901-555-7878");
INSERT INTO Customer VALUES ("Maya Robinson", "615-555-6060");
INSERT INTO Customer VALUES ("Noah Thompson", "731-555-2020");
INSERT INTO Customer VALUES ("Olivia Brooks", "865-555-9090");

-- Locations
INSERT INTO Location(CustomerName, StreetAddress, City, State, ZipCode) VALUES
("Alice Johnson", "124 Maple Street", "Knoxville", "Tennessee", "37917"),
("Brian Matthews", "88 Oak Ridge Drive", "Oak Ridge", "Tennessee", "37830"),
("Cynthia Lee", "241 Cherry Blossom Ln", "Murfreesboro", "Tennessee", "37130"),
("David Kim", "515 Hillside Rd", "Nashville", "Tennessee", "37212"),
("Elena Torres", "79 Riverbend Way", "Memphis", "Tennessee", "38103"),
("Frank Harris", "903 Pine Hollow Ct", "Knoxville", "Tennessee", "37923"),
("Grace Walker", "321 Sunset Blvd", "Jackson", "Tennessee", "38301"),
("Henry Adams", "4408 Meadowview Dr", "Brentwood", "Tennessee", "37027"),
("Isabella Wright", "9908 Willow Ridge Pl", "Clarksville", "Tennessee", "37042"),
("Jason Patel", "211 Forest Trail", "Chattanooga", "Tennessee", "37421"),
("Karen Scott", "1407 Cedar Brook Ln", "Maryville", "Tennessee", "37803"),
("Liam Turner", "502 Elmwood Ave", "Memphis", "Tennessee", "38111"),
("Maya Robinson", "604 Fairway Dr", "Franklin", "Tennessee", "37064"),
("Noah Thompson", "210 Greenfield Ct", "Paris", "Tennessee", "38242"),
("Olivia Brooks", "750 Harbor View Rd", "Knoxville", "Tennessee", "37919");

-- Billing Information Services
INSERT INTO Billing (CustomerName, AmountDue, CreditCardOnFile, LastPaymentDate, IsLate, ItemType, ItemName) VALUES
("Alice Johnson", 65, "1123", "2025-09-28", 0, "Service", "Residential Internet (Basic)"),
("Brian Matthews", 150, "3421", "2025-09-30", 0, "Service", "Internet + TV"),
("Cynthia Lee", 95, "7777", "2025-10-01", 1, "Service", "Residential Internet (Gigabit)"),
("David Kim", 35, "8888", "2025-09-22", 0, "Service", "Basic Cable Package"),
("Elena Torres", 180, "1199", "2025-09-10", 1, "Service", "Triple Bundle (Internet + TV + Phone)"),
("Frank Harris", 55, "5050", "2025-10-02", 0, "Service", "Residential Internet (Basic)"),
("Grace Walker", 40, "8741", "2025-09-29", 0, "Service", "Home Landline (VolP)"),
("Henry Adams", 250, "3311", "2025-09-12", 1, "Service", "Business Internet Plan"),
("Isabella Wright", 130, "2680", "2025-09-25", 0, "Service", "Internet + TV"),
("Jason Patel", 60, "9034", "2025-09-30", 0, "Service", "Business VolP Line"),
("Karen Scott", 80, "6742", "2025-09-17", 0, "Service", "Internet + Phone"),
("Liam Turner", 25, "2211", "2025-09-26", 0, "Service", "Sports Package"),
("Maya Robinson", 90, "6655", "2025-09-29", 0, "Service", "Residential Internet (Gigabit)"),
("Noah Thompson", 70, "9900", "2025-09-27", 0, "Service", "Internet + Phone"),
("Olivia Brooks", 55, "4874", "2025-10-03", 0, "Service", "Residential Internet (Basic)");

-- Billing Information Equipment
INSERT INTO Billing (CustomerName, AmountDue, CreditCardOnFile, LastPaymentDate, IsLate, ItemType, ItemName) VALUES
("Alice Johnson", 10, "1123", "2025-09-28", 0, "Equipment", "Modem"),
("Brian Matthews", 40, "3421", "2025-09-30", 0, "Equipment", "Wireless Router"),
("Cynthia Lee", 15, "7777", "2025-10-01", 1, "Equipment", "Cable TV Box"),
("David Kim", 6, "8888", "2025-09-22", 0, "Equipment", "Streaming Device (Roku/FireTV)"),
("Elena Torres", 20, "1199", "2025-09-10", 1, "Equipment", "Digital Video Recorder (DVR)"),
("Frank Harris", 15, "5050", "2025-10-02", 0, "Equipment", "Backup Power Supply (UPS)"),
("Grace Walker", 8, "8741", "2025-09-29", 0, "Equipment", "Ethernet Switch"),
("Henry Adams", 80, "3311", "2025-09-12", 1, "Equipment", "Fiber ONT (Optical Network Terminal)"),
("Isabella Wright", 12, "2680", "2025-09-25", 0, "Equipment", "Smart Hub / Gateway"),
("Jason Patel", 10, "9034", "2025-09-30", 0, "Equipment", "Smart Cameras"),
("Karen Scott", 40, "6742", "2025-09-17", 0, "Equipment", "Wireless Router"),
("Liam Turner", 15, "2211", "2025-09-26", 0, "Equipment", "Cable TV Box"),
("Maya Robinson", 6, "6655", "2025-09-29", 0, "Equipment", "Smart Thermostat"),
("Noah Thompson", 10, "9900", "2025-09-27", 0, "Equipment", "Modem"),
("Olivia Brooks", 12, "4874", "2025-10-03", 0, "Equipment", "Smart Hub / Gateway");