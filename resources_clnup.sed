# Add newline after item_quantity
s/item_quantity/item_quantity\
/g 
# Remove all quoted ctrl-Ms
s/\\\\//g
# Remove all quoted commas
s/\\\,//g
# Remove all double backslashes at the end of a column
s/\\\\\"\,\"/\"\,\"/g
# Replace all escaped double quotes not preceded by alphabets or space with "in"
s/\([^a-zA-Z ]\)\\\"/\1in/g
# Replace all escaped double quotes preceded by a number and a space with "in"
s/\([0-9]\) \\\"/\1in/g
# Remove all escaped double quote
s/\\\"//g
