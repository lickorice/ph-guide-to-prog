# Get collection of items:
item1 = input()
item2 = input()
item3 = input()
item4 = input()
item5 = input()

# Our position, or "index":
position = int( input() )

# Get our item at position:
if (position == 1):
    our_item = item1
elif (position == 2):
    our_item = item2
elif (position == 3):
    our_item = item3
elif (position == 4):
    our_item = item4
elif (position == 5):
    our_item = item5
else:
    our_item = "Item not found!"

# Print our item
print(our_item)