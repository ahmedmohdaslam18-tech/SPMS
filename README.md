# SPMS

Project Title : Smart Parking Lot Management System

Project ID : 22

Project Group ID : 14

	Team Members 	|  Enrollment
			
Mestry Yash Madhukar	29\n
Ahmed Mohammed Aslam 	30\n
Rao Kaushal Dharmendra	31\n

Project Description :

# 1. Overview
SPLMS is a console-based C++ application that automates the day-to-day operations of a multi-floor parking facility. It handles vehicle entry, intelligent slot allocation based on vehicle type and floor, time-based billing on exit, live availability tracking, and vehicle search.

# 2. Objectives
Eliminate manual register-keeping and reduce human error in slot assignment and billing.

Provide real-time visibility of free and occupied slots across floors and vehicle categories.

Generate accurate and transparent bills based on parking duration and vehicle type.

# 3. Key Features
1	Multi-floor layout	3 floors; each floor holds separate blocks for bikes, cars, and trucks
2	Vehicle categorization	Bike, Car, Truck with different slot capacities and rates
3	Automatic slot allocation	First free slot on the lowest floor for the given vehicle type
4	Entry ticket generation	Ticket ID, plate, slot, entry time, hourly rate
5	Time-based billing	Duration rounded up to next hour; minimum 1 hour
6	Live availability view	Free/total slots per floor per vehicle type
7	Active vehicle listing	Currently parked vehicles with elapsed time
8	Vehicle search	Finds active vehicles or past transactions by plate

Interface: Console (menu-driven)

# MVP-1
A C++ console-based MVP for a Smart Parking Lot System. It demonstrates vehicle entry with auto-slot allocation, duplicate parking prevention, and time-based billing upon exit, utilizing object-oriented structures without external dependencies.

# MVP-2
Building upon MVP 1, this version introduces the Live Availability feature. The parking lot capacity has been expanded to 6 slots (2 per vehicle type) to demonstrate this. Users can now select option 3 to view a real-time dashboard of every slot, showing whether it is currently [ FREE ] or [ OCCUPIED by 'plate' ].
