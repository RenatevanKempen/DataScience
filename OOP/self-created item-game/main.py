from item import Item
kitchenknife = Item("Kitchen Knife")
kitchenknife.set_description("This knife can be used to cut vegetables")
#kitchen.describe()

sword = Item("Sword")
sword.set_description("This sword was used by the best knights in the past, now it's yours!!")

canon = Item("Canon")
canon.set_description("To do real damage, use this robust canon")

kitchenknife.item_link(sword, "upgrade")
sword.item_link(canon, "ultimate")
canon.item_link(sword, "back")
sword.item_link(kitchenknife, "downgrade")

current_item = kitchenknife          

while True:		
    print("\n")         
    current_item.get_details()         
    command = input("> ")    
    current_item = current_item.move(command) 
    
