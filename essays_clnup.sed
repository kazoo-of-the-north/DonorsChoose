# Add newline after impact_letter column
s/impact_letter/impact_letter\
/g
# Remove all quoted ctrl-Ms
s/\\\\//g
# Remove all double backslashes that are followed by double quotes
s/\\\\\"/\"/g
# Replace escaped double quotes with escaped single quotes
s/\\\"/\\'/g
# Remove all quoted commas
s/\\,//g
