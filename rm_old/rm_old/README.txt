Jim Schlough
04-23-2016

The purpose of this application is to serve as a data cleaner, to sort out records from the csv open data files gathered from the Donor Choose website.

This is done in partial fulfillment of the requirements for CSC E-107 Intro to Data Science.
rm_old fileInName bottomCutOffDate topCutOffDate dateFieldIndex

fileInName
The fileInName is both the path and the name of the file and may contain spaces if these spaces are preceded by a backslash.

bottomCutOffDate
and
topCutOffDate
These are numerical expressions of the earliest and latest date within the test column, so

20140100 is a value preceding January 1st, 2014

20141300 is a value succeeding December 31st, 2014

dateFieldIndex

41 denotes the 41st column index of the csv file, with the first column having and index of 1.


These are the commands from my terminal's history used to run rm_old:

./rm_old /Users/jimschlough/Documents/Harvard/CSC-E107/Final\ project/opendata_projects.csv 20140100 20141300 41

wc -l opendata_projects_output.csv

The wc (word count) command shows how many lines are in the file produced.