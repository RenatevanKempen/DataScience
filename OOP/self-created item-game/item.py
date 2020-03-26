class Item():
  def __init__(self, item_name):
    self.name = item_name
    self.description = None
  
  def set_description(self, item_description):
    self.description = item_description
    self.items_linked = {}
    
  def get_description(self):
    return self.description
    
  def set_name(self, name):
      self.name = name
      self.items_linked = {}
      
  def get_name(self):
    return self.name
  
  def describe(self):
    print(self.description)
    
  def item_link(self, item_to_link, direction):
    self.items_linked[direction] = item_to_link
   # print( self.name + " linked rooms :" + repr(self.linked_rooms) )
  
  def get_details(self):
    print("\n")
    print("The " + self.name)
    print("--------------------------")
    print(self.description)
    for direction in self.items_linked:
      item = self.items_linked[direction]
      print("To use " + item.get_name() + ', enter: ' + direction)
      
  #add code to move between rooms
  def move(self, direction):
    if direction in self.items_linked:
      return self.items_linked[direction]
    else:
      print("You can't use this item")
      return self