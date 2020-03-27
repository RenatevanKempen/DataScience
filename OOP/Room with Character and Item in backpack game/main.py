from room import Room
from character import Enemy
from character import Friend
from item import Item
backpack = []

kitchen = Room("Kitchen")
kitchen.set_description("A dark an dirty room buzzing with flies")

dining_hall = Room("Dining Hall")
dining_hall.set_description("A light room with a large table and lot's of comfy chairs")

ballroom = Room("Ballroom")
ballroom.set_description("A beautifull pink room with a dark wooden floor to dance on")

bedroom = Room("Bedroom")
bedroom.set_description("Small but cosy room with a huge bed in it")

kitchen.link_room(dining_hall, "south")
dining_hall.link_room(ballroom, "west")
ballroom.link_room(dining_hall, "east")
dining_hall.link_room(kitchen, "north")
bedroom.link_room(ballroom, "south")
ballroom.link_room(bedroom, "north")


dave = Enemy("Dave", "A smelly zombie")
dave.set_conversation("Brrlgrh... rgrhl... brains...")
dave.set_weakness("Kitchen Knife")
dining_hall.set_character(dave)

bill = Enemy("Bill", "A monster that looks like Frankenstein")
bill.set_conversation("AAHHHGGGRRR, I'm going to KILLLL you!!")
bill.set_weakness("canon")
bedroom.set_character(bill)

lisa = Friend("Lisa", "a kind and warm person")
lisa.set_conversation("Hi there, do you want a hugg?")
kitchen.set_character(lisa)

current_room = kitchen    

kitchenknife = Item("Kitchen Knife")
kitchenknife.set_description("This knife can be used to cut vegetables")
kitchen.set_item(kitchenknife)

sword = Item("Sword")
sword.set_description("This sword was used by the best knights in the past, now it's yours!!")
bedroom.set_item(sword)

canon = Item("Canon")
canon.set_description("To do real damage, use this robust canon")
ballroom.set_item(canon)

keepGoing = True
while keepGoing:		
    print("\n")         
    current_room.get_details() 
    
    item_in_room = current_room.get_item()
    if item_in_room is not None:
      item_in_room.get_details() 
    else:
      print("There is no item in this room")
    #  command_item = input("item:")
    #  item_in_room(command_item)
      
    inhabitant = current_room.get_character()
    if inhabitant is not None:
      print("\n")
      print("There is also someone in this room:")
      print("-----------------------------------")
      inhabitant.describe()
      
    command = input("> ") 
    
    # Check whether a direction was typed
    if command in ["north", "south", "east", "west"]:
      current_room = current_room.move(command)
    elif command == "talk":
      inhabitant.talk()
    elif command == "take":
      print('This '+ item_in_room.name + " will now be put in the backpack")
      backpack.append(item_in_room.name)
      print(backpack)
      current_room.set_item(None)
    elif command == "hugg":
      if inhabitant == None:
        print("there is no one here to hug:(")
      elif isinstance(inhabitant, Enemy):
        print("I wouldn't do this if I were you..... WHOHAHA!")
      else:
        print(inhabitant.name + " gives you a bigg hugg back")
    else:
      if inhabitant == None or isinstance(inhabitant, Friend):
        print("there is no on here to fight with! Continue to the next room")
      else:
        print("What will you fight with?")
        fight_with = input()
        if fight_with in backpack:
          x  = inhabitant.fight(fight_with)
          if x == False:
            print("GAME OVER")         
            keepGoing = False
          else:
            print("Well done, you have slayed the ENEMY!!")
            current_room.set_character(None)
            keepGoing = True
        else: 
          print("you do not have this item in the backpack")

        
        
        