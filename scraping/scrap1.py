import webbrowser
from bs4 import BeautifulSoup
from urllib.request import urlopen
import re
import requests
site="https://www.flipkart.com/search?q=lenovo+mobile&sid=tyy%2C4io&as=on&as-show=on&otracker=AS_QueryStore_OrganicAutoSuggest_1_4_na_na_na&otracker1=AS_QueryStore_OrganicAutoSuggest_1_4_na_na_na&as-pos=1&as-type=RECENT&suggestionId=lenovo+mobile%7CMobiles&requestId=b4f3f4c7-6d14-4e3d-acba-8f3c771dbab3&as-backfill=on"
page=urlopen(site)
res=requests.get(site)
print(res)
soup=BeautifulSoup(page,'lxml')
nameofproduct=soup.find_all('div',{'class':'_3wU53n'})
priceofproduct=soup.find_all('div',{'class':'_1vC4OE _2rQ-NK'})
strtoinput=''
for name in range(0,len(nameofproduct)):
    bla='&#8377;'
    for i in priceofproduct[name].decode_contents():
        if(i.isdigit() or i==','):
            bla+=i      
    strtoinput+=nameofproduct[name].decode_contents()+" : "+bla+"\n<br>"
    #print(nameofproduct[name].decode_contents()," : ",priceofproduct[name].decode_contents(),"\n")
print(strtoinput)


message="""
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>
            Test Web Page with Python
        </title>
    </head>
    <body>
        <h1>Price of iPhones!</h1>
        <p>"""+strtoinput+"""</p>
    </body>
</html>"""
f=open("D:\Applications Non pes\Web\scraping\\test.html",'w')
f.write(message)
f.close()
filename="D:\Applications Non pes\Web\scraping\\test.html"
webbrowser.open_new_tab(filename)