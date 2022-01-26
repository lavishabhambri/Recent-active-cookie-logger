# Submission by Lavisha Bhambri

## Steps to run the code
1. Download all the files from the github link.
2. Open the root directory.
3. Enter the command in your terminal ```make```.
4. Now enter the commands in the format, ```./most_active_cookie cookie_log.csv -d 2018-12-08```.

## Approach
1. Processed the CSV to extract the cookie logs of the given input date in ```returnAllCookiesOnGivenDate``` function.
2. From all the cookie logs of the given date, I filtered out the cookies with maximum frequency in ```findCookiesWithMaxFrequency``` function.
3. Printed the cookies with maximum frequency taking into account their coherence of occurences in the logs in ```printCookies``` function.
