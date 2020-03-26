from room import Room
kitchen = Room("Kitchen")
kitchen.set_description("A dark an dirty room buzzing with flies")
#kitchen.describe()

dining_hall = Room("Dining Hall")
dining_hall.set_description("A light room with a large table and lot's of comfy chairs")

ballroom = Room("Ballroom")
ballroom.set_description("A beautifull pink room with a dark wooden floor to dance on")

kitchen.link_room(dining_hall, "south")
dining_hall.link_room(ballroom, "west")
ballroom.link_room(dining_hall, "east")
dining_hall.link_room(kitchen, "north")

#dining_hall.get_details()

#kitchen.get_details()

#sballroom.get_details()

current_room = kitchen          

while True:		
    print("\n")         
    current_room.get_details()         
    command = input("> ")    
    current_room = current_room.move(command) 