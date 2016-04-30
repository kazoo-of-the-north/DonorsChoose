# Add newline after donation_message 
s/donation_message/donation_message\
/g
# Replace all quoted ctrl-Ms 
s/\\\\//g
# Removed all \\ at the end of a field string 
s/\\\\\"\_$/\"/g
# Remove all double backslashes that are in a string by itself
s/\\\\\"/\"/g
# Replace quoted double quotes with quoted single quotes
s/\\\"/\\\'/g
# Remove all quoted commas
s/\\\,//g
