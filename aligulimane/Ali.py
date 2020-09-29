from kivy.app import App
from random import randint
from kivy.uix.widget import Widget
from kivy.properties import StringProperty
from kivy.core.window import Window
from kivy.uix.button import Button
from kivy.graphics import Ellipse
from kivy.uix.floatlayout import FloatLayout
from kivy.config import Config
from kivy.properties import ObjectProperty
from kivy.core.window import Window
from pygame import mixer
import pygame
#Window.fullscreen = True
pygame.init()
Window.clearcolor=(85/255.0,52/255.0,43/255.0,1)
Config.set('graphics', 'resizable', True)
class Houses(Widget):
    pass
mixer.music.load('D:\PES\python\\test.wav')
mixer.music.play(-1)
def sad(b):
    print("this is also",b)
def example(a):
    print("hello this is",a)
class AliGame(Widget):
    def __init__(self, **kwargs):
        super(AliGame, self).__init__(**kwargs)

    def say_hello(self,y):
        if y>0 and y<=7:
            example(y)
        elif y>7 and y<=14:
            sad(y)


class AliApp(App):
    def build(self):
        game=AliGame()
        return game

AliApp().run()
for i in range(1,10):
    print(i)

