from gtts import gTTS
import os
fh=open("D:\\PES\\python\\write whatsapp msg\\1.txt","r")
myText1=fh.read().replace("\n"," ")
myText="Hello, This is a python program to convert TEXT to voice. and Here is a pause"
language='en'
output=gTTS(text=myText , lang=language)
output.save("D:\\PES\\python\\output.mp3")
os.system("start D:\\PES\\python\\output.mp3")