from room import Room
from character import Enemy
from character import Friend
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

dave = Enemy("Dave", "A smelly zombie")
dave.set_conversation("Brrlgrh... rgrhl... brains...")
dave.set_weakness("cheese")
dining_hall.set_character(dave)

bill = Enemy("Bill", "A monster that looks like Frankenstein")
bill.set_conversation("AAHHHGGGRRR, I'm going to KILLLL you!!")
bill.set_weakness("money")
ballroom.set_character(bill)

lisa = Friend("Lisa", "a kind and warm person")
lisa.set_conversation("Hi there, do you want a hugg?")
kitchen.set_character(lisa)

current_room = kitchen          

keepGoing = True
while keepGoing:		
    print("\n")         
    current_room.get_details() 
    inhabitant = current_room.get_character()
    if inhabitant is not None:
      inhabitant.describe()
    command = input("> ") 
    
    # Check whether a direction was typed
    if command in ["north", "south", "east", "west"]:
      current_room = current_room.move(command)
    elif command == "talk":
      inhabitant.talk()
    elif command == "hugg":
      if inhabitant == None:
        print("there is no one here to hug:(")
      elif isinstance(inhabitant, Enemy):
        print("I wouldn't do this if I were you..... WHOHAHA!")
      else:
        print("hi, my name is " + inhabitant.name + " and I will give you a bigg hugg back")
    else:
      if inhabitant == None or isinstance(inhabitant, Friend):
        print("there is no on here to fight with! Continue to the next room")
      else:
        print("What will you fight with?")
        fight_with = input()
        x  = inhabitant.fight(fight_with)
        if x == False:
         print("GAME OVER")         
         keepGoing = False
        else:
         print("Well done, you have slayed the ENEMY!!")
         current_room.set_character(None)
         keepGoing = True

        
        
        