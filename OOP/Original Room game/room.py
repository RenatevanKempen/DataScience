class Room():
  def __init__(self, room_name):
    self.name = room_name
    self.decription = None
    
    #add your code here (make sure it is indented)
  def set_description(self, room_description):
    self.description = room_description
    self.linked_rooms = {}
    
  def get_description(self):
    return self.description
    
  def set_name(self, name):
      self.name = name
      self.linked_rooms = {}
      
  def get_name(self):
    return self.name
  
  def describe(self):
    print(self.description)
    
  #add link_room method here
  def link_room(self, room_to_link, direction):
    self.linked_rooms[direction] = room_to_link
   # print( self.name + " linked rooms :" + repr(self.linked_rooms) )
   
  #add code here to display the report
  def get_details(self):
    print("\n")
    print("The " + self.name)
    print("--------------------------")
    print(self.description)
    for direction in self.linked_rooms:
      room = self.linked_rooms[direction]
      print("The " + room.get_name() + ' is ' + direction)
      
  #add code to move between rooms
  def move(self, direction):
    if direction in self.linked_rooms:
      return self.linked_rooms[direction]
    else:
      print("You can't go that way")
      return self
      