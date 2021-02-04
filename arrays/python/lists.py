# Declare an empty list
items = []
items.append(input())
items.append(input())
items.append(input())
items.append(input())
items.append(input())

# Our position, or "index":
index = int( input() )

# Print our list:
print(items)

# Get our item at position:
our_item = items[index]

# Print our item
print(our_item)
# Note that instead of printing "3", we print
# "4", because our arrays START AT 0.