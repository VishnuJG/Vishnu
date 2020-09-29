import speech_recognition as sr
from gtts import gTTS
import os
r=sr.Recognizer()
with sr.Microphone() as source:
    print("Start")
    audio=r.listen(source)
    print("Stop")
try:
    print(r.recognize_google(audio))
    #language='en'
    #output=gTTS(text=r.recognize_google(audio) , lang=language)
    #output.save("D:\\PES\\python\\output.mp3")
    #os.system("start D:\\PES\\python\\output.mp3")
except:
    pass

