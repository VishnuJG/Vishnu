import pygame
from pygame import draw
from pygame.locals import *
from time import sleep

clock=pygame.time.Clock()
x= {1:6,2:6,3:6,4:6,5:6,6:6,7:6,8:6,9:6,10:6,11:6,12:6,13:6,14:6}
player1count=0
player2count=0
pygame.init()
pos={1:(125,443),2:(250,443),3:(375,443),4:(500,443),5:(625,443),6:(750,443),7:(875,443),8:(875,193),9:(750,193),10:(625,193),11:(500,193),12:(375,193),13:(250,193),14:(125,193),}
screen=pygame.display.set_mode((1000,600), HWSURFACE | DOUBLEBUF | RESIZABLE) #width and height
running=True
pygame.display.set_caption("Space Invasion")
icon=pygame.image.load("D:\PES\python\Alita.jpeg")
pygame.display.set_icon(icon)
playerimage=pygame.image.load("D:\PES\python\Ali guli mane\\aligul.png")
spaceimg=pygame.image.load("D:\PES\python\Ali guli mane\space.png")
surface = pygame.display.get_surface()
spaceimg=pygame.transform.scale(spaceimg,(surface.get_width(),surface.get_height()))
plusimg=pygame.image.load("D:\PES\python\Ali guli mane\\plus.png")
plusimg=pygame.transform.scale(plusimg,(50,50))
num1=pygame.image.load("D:\PES\python\Ali guli mane\\1.png")
num1=pygame.transform.scale(num1, (50, 50))
num2=pygame.image.load("D:\PES\python\Ali guli mane\\2.png")
num2=pygame.transform.scale(num2, (50, 50))
num3=pygame.image.load("D:\PES\python\Ali guli mane\\3.png")
num3=pygame.transform.scale(num3, (50, 50))
num4=pygame.image.load("D:\PES\python\Ali guli mane\\4.png")
num4=pygame.transform.scale(num4, (50, 50))
num5=pygame.image.load("D:\PES\python\Ali guli mane\\5.png")
num5=pygame.transform.scale(num5, (50, 50))
num6=pygame.image.load("D:\PES\python\Ali guli mane\\6.png")
num6=pygame.transform.scale(num6, (50, 50))
num7=pygame.image.load("D:\PES\python\Ali guli mane\\7.png")
num7=pygame.transform.scale(num7, (50, 50))
num8=pygame.image.load("D:\PES\python\Ali guli mane\\8.png")
num8=pygame.transform.scale(num8, (50, 50))
num9=pygame.image.load("D:\PES\python\Ali guli mane\\9.png")
num9=pygame.transform.scale(num9, (50, 50))
num0=pygame.image.load("D:\PES\python\Ali guli mane\\zero.png")
num0=pygame.transform.scale(num0, (50, 50))

playerX=50
playerY=50
from pygame import mixer





def run(l, m, n):
    x[m] = 0
    while n > 0:
        m += 1
        if m >= 15:
            m = 1
        x[m] += 1
        for i in range(1,100):
            screen.blit(plusimg,pos[m])
        n -= 1
    m = m + 1
    if m >= 15:
        m = 1
    if x[m] != 0:
        run(l, m, x[m])
    elif x[m] == 0:
        m = m + 1
        if m >= 15:
            m = 1
        if x[m] == 0:
            pass
        else:
            if l == 1:
                global player1count
                player1count += x[m]
                x[m] = 0
            elif l == 2:
                global player2count
                player2count += x[m]
                x[m] = 0


def ck():
    flag = 0
    for i in range(1, 8):
        if x[i] != 0:
            flag = 0
            break;
        flag = 1
    if flag == 1:
        return flag;

    for i in range(8, 15):
        if x[i] != 0:
            flag = 0
            break;
        flag = 2
    if flag == 2:
        return flag;
    return flag;


def start(l, m):
    m=int(m)
    if l==1 and m>0 and m<8 and x[m]!=0:
        count = x[m]
        run(l, m, count)
    elif l==2 and m>7 and m<15 and x[m]!=0:
        count = x[m]
        run(l, m, count)
    else:
        print("Invalid input")
        largeText = pygame.font.Font('freesansbold.ttf', 50)
        TextSurf = largeText.render("Invalid input\nPlayer", True, (255, 0, 0))
        TextRect = TextSurf.get_rect()
        TextRect.center = 400, 100
        screen.blit(TextSurf, TextRect)
        pygame.display.flip()
        clock.tick(3000)
        largeText = pygame.font.Font('freesansbold.ttf', 50)
        TextSurf = largeText.render(str(l), True, (255, 0, 0))
        TextRect = TextSurf.get_rect()
        TextRect.center = 400, 250
        screen.blit(TextSurf, TextRect)
        pygame.display.flip()
        clock.tick(3000)
        largeText = pygame.font.Font('freesansbold.ttf', 50)
        TextSurf = largeText.render("Loses 2 points", True, (255, 0, 0))
        TextRect = TextSurf.get_rect()
        TextRect.center = 400, 350
        screen.blit(TextSurf, TextRect)
        pygame.display.flip()
        clock.tick(3000)
        global player1count
        global player2count
        if l==1:
            player1count-=2
        elif l==2:
            player2count-=2
        errorsound=mixer.Sound("D:\PES\python\Ali guli mane\Wrong-answer-sound-effect.wav")
        errorsound.play()

i=1
def clear():
    global player1count
    global player2count
    for i in range(1, 8):
        player1count += x[i]
    for i in range(8, 15):
        player2count += x[i]

check = 0
def write(text,w):
    largeText = pygame.font.Font('freesansbold.ttf', 15)
    TextSurf = largeText.render(text, True, (255, 0, 0))
    TextRect = TextSurf.get_rect()
    TextRect.center = w
    screen.blit(TextSurf, TextRect)
def disp(v,i,c):
    if c==1:
        if v==1:
            screen.blit(num1,(i[0]-20,i[1]-20))
        elif v==2:
            screen.blit(num2,(i[0]-20,i[1]-20))
        elif v==3:
            screen.blit(num3,(i[0]-20,i[1]-20))
        elif v==4:
            screen.blit(num4,(i[0]-20,i[1]-20))
        elif v==5:
            screen.blit(num5,(i[0]-20,i[1]-20))
        elif v==6:
            screen.blit(num6,(i[0]-20,i[1]-20))
        elif v==7:
            screen.blit(num7,(i[0]-20,i[1]-20))
        elif v==8:
            screen.blit(num8,(i[0]-20,i[1]-20))
        elif v==9:
            screen.blit(num9,(i[0]-20,i[1]-20))
        elif v==0:
            screen.blit(num0,(i[0]-20,i[1]-20))
    elif c>1:
        if v==1:
            screen.blit(num1,(i[0]-55,i[1]-20))
        elif v==2:
            screen.blit(num2,(i[0]-55,i[1]-20))
        elif v==3:
            screen.blit(num3,(i[0]-55,i[1]-20))
        elif v==4:
            screen.blit(num4,(i[0]-55,i[1]-20))
        elif v==5:
            screen.blit(num5,(i[0]-55,i[1]-20))
        elif v==6:
            screen.blit(num6,(i[0]-55,i[1]-20))
        elif v==7:
            screen.blit(num7,(i[0]-55,i[1]-20))
        elif v==8:
            screen.blit(num8,(i[0]-55,i[1]-20))
        elif v==9:
            screen.blit(num9,(i[0]-55,i[1]-20))
        elif v==0:
            screen.blit(num0,(i[0]-55,i[1]-20))

def display():
    for i in range(1,15):
        n=x[i]
        count=1
        dig1=n%10
        n=n//10
        disp(dig1,pos[i],count)
        while n>0:
            count+=1
            dig1=n%10
            n=n//10
            disp(dig1,pos[i],count)

def board(x,y):
    screen.blit(playerimage,(x,y))
    #screen.blit(plusimg,pos[3])
    for i in range(1,15):
        pygame.draw.circle(screen, (85, 52, 43), pos[i], 59, 1)





check=0
begin=0
st=0
while running:

    if begin==0:
        for op in range(1,15):
            x[op]=6
        player1count=0
        player2count=0
        surface = pygame.display.get_surface()
        pygame.draw.rect(screen,(85, 52, 43),(0, 0, surface.get_width(), surface.get_height()))
        pygame.draw.rect(screen,(85, 52, 43),(400,93,200,100))
        buttonstart = pygame.Rect(400,93,200,100)
        largeText = pygame.font.Font('freesansbold.ttf', 50)
        TextSurf = largeText.render("START", True, (212,175,55))
        TextRect = TextSurf.get_rect()
        TextRect.center = 500,142
        screen.blit(TextSurf, TextRect)
        pygame.draw.rect(screen, (85, 52, 43), (400, 453, 200, 100))
        buttonquit = pygame.Rect(400, 453, 200, 100)
        largeText = pygame.font.Font('freesansbold.ttf', 50)
        TextSurf = largeText.render("EXIT", True, (212,175,55))
        TextRect = TextSurf.get_rect()
        TextRect.center = 500, 502
        screen.blit(TextSurf, TextRect)
        pygame.draw.rect(screen, (85, 52, 43), (375, 253, 250, 100))
        buttonrestart = pygame.Rect(400, 253, 200, 100)
        largeText = pygame.font.Font('freesansbold.ttf', 50)
        TextSurf = largeText.render("RESTART", True, (212,175,55))
        TextRect = TextSurf.get_rect()
        TextRect.center = 500, 302
        screen.blit(TextSurf, TextRect)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.MOUSEBUTTONDOWN:
                mouse_pos = event.pos  # gets mouse position
                if buttonstart.collidepoint(mouse_pos):
                    # prints current location of mouse
                    begin=2
                    st=1
                elif buttonquit.collidepoint((mouse_pos)):
                    running=False
                elif buttonrestart.collidepoint((mouse_pos)):
                    begin=0
                    i=1
    elif begin==1:
        if player1count<player2count and check!=0:
            screen.blit(spaceimg, (0, 0))

            largeText = pygame.font.Font('freesansbold.ttf', 50)
            TextSurf = largeText.render("Player 2 has won the game", True, (255, 0, 0))
            TextRect = TextSurf.get_rect()
            TextRect.center = 400, 100
            screen.blit(TextSurf, TextRect)
            pygame.display.flip()
            clock.tick(300)
            largeText = pygame.font.Font('freesansbold.ttf', 15)
            TextSurf = largeText.render("Player 1 score:", True, (255, 0, 0))
            TextRect = TextSurf.get_rect()
            TextRect.center = 120, 220
            screen.blit(TextSurf, TextRect)
            largeText = pygame.font.Font('freesansbold.ttf', 15)
            TextSurf = largeText.render(str(player1count), True, (255, 0, 0))
            TextRect = TextSurf.get_rect()
            TextRect.center = 120, 240
            screen.blit(TextSurf, TextRect)
            largeText = pygame.font.Font('freesansbold.ttf', 15)
            TextSurf = largeText.render(str(player2count), True, (255, 0, 0))
            TextRect = TextSurf.get_rect()
            TextRect.center = 895, 240
            screen.blit(TextSurf, TextRect)
            largeText = pygame.font.Font('freesansbold.ttf', 15)
            TextSurf = largeText.render("Player 2 score", True, (255, 0, 0))
            TextRect = TextSurf.get_rect()
            TextRect.center = 895, 220
            screen.blit(TextSurf, TextRect)
            st=0
            pygame.draw.rect(screen, (85, 52, 43), (375, 253, 250, 100))
            buttonres = pygame.Rect(400, 253, 200, 100)
            largeText = pygame.font.Font('freesansbold.ttf', 50)
            TextSurf = largeText.render("RESTART", True, (212, 175, 55))
            TextRect = TextSurf.get_rect()
            TextRect.center = 500, 302
            screen.blit(TextSurf, TextRect)
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                if event.type == pygame.MOUSEBUTTONDOWN:
                    mouse_pos = event.pos  # gets mouse position
                    opt = 0
                    if buttonres.collidepoint(mouse_pos):
                        st = 1
                        begin=0
                        i=1
        elif check !=0 and player1count>player2count:
            screen.blit(spaceimg,(0,0))
            #for f in range(1,100):
            largeText = pygame.font.Font('freesansbold.ttf', 50)
            TextSurf = largeText.render("Player 1 has won the game", True, (0, 0, 255))
            TextRect = TextSurf.get_rect()
            TextRect.center = 400, 100
            screen.blit(TextSurf, TextRect)
            pygame.display.flip()
            clock.tick(30)
            largeText = pygame.font.Font('freesansbold.ttf', 25)
            TextSurf = largeText.render("Player 1 score:", True, (255, 0, 0))
            TextRect = TextSurf.get_rect()
            TextRect.center = 120, 220
            screen.blit(TextSurf, TextRect)
            largeText = pygame.font.Font('freesansbold.ttf', 25)
            TextSurf = largeText.render(str(player1count), True, (255, 0, 0))
            TextRect = TextSurf.get_rect()
            TextRect.center = 120, 240
            screen.blit(TextSurf, TextRect)
            largeText = pygame.font.Font('freesansbold.ttf', 25)
            TextSurf = largeText.render(str(player2count), True, (255, 0, 0))
            TextRect = TextSurf.get_rect()
            TextRect.center = 895, 240
            screen.blit(TextSurf, TextRect)
            largeText = pygame.font.Font('freesansbold.ttf', 25)
            TextSurf = largeText.render("Player 2 score:", True, (255, 0, 0))
            TextRect = TextSurf.get_rect()
            TextRect.center = 895, 220
            screen.blit(TextSurf, TextRect)
            st=0
            pygame.draw.rect(screen, (85, 52, 43), (375, 253, 250, 100))
            buttonres = pygame.Rect(400, 253, 200, 100)
            largeText = pygame.font.Font('freesansbold.ttf', 50)
            TextSurf = largeText.render("RESTART", True, (212, 175, 55))
            TextRect = TextSurf.get_rect()
            TextRect.center = 500, 302
            screen.blit(TextSurf, TextRect)
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                if event.type == pygame.MOUSEBUTTONDOWN:
                    mouse_pos = event.pos  # gets mouse position
                    opt=0
                    if buttonres.collidepoint(mouse_pos):
                        st=1
                        begin=0
                        i=1

        elif check !=0 and player1count==player2count:
            screen.blit(spaceimg,(0,0))
            #for f in range(1,100):
            largeText = pygame.font.Font('freesansbold.ttf', 50)
            TextSurf = largeText.render("DRAW!!!", True, (0, 0, 255))
            TextRect = TextSurf.get_rect()
            TextRect.center = 400, 100
            screen.blit(TextSurf, TextRect)
            pygame.display.flip()
            clock.tick(30)
            largeText = pygame.font.Font('freesansbold.ttf', 25)
            TextSurf = largeText.render("Player 1 score:", True, (255, 0, 0))
            TextRect = TextSurf.get_rect()
            TextRect.center = 120, 220
            screen.blit(TextSurf, TextRect)
            largeText = pygame.font.Font('freesansbold.ttf', 25)
            TextSurf = largeText.render(str(player1count), True, (255, 0, 0))
            TextRect = TextSurf.get_rect()
            TextRect.center = 120, 240
            screen.blit(TextSurf, TextRect)
            largeText = pygame.font.Font('freesansbold.ttf', 25)
            TextSurf = largeText.render(str(player2count), True, (255, 0, 0))
            TextRect = TextSurf.get_rect()
            TextRect.center = 895, 240
            screen.blit(TextSurf, TextRect)
            largeText = pygame.font.Font('freesansbold.ttf', 25)
            TextSurf = largeText.render("Player 2 score:", True, (255, 0, 0))
            TextRect = TextSurf.get_rect()
            TextRect.center = 895, 220
            screen.blit(TextSurf, TextRect)
            st=0
            pygame.draw.rect(screen, (85, 52, 43), (375, 253, 250, 100))
            buttonres = pygame.Rect(400, 253, 200, 100)
            largeText = pygame.font.Font('freesansbold.ttf', 50)
            TextSurf = largeText.render("RESTART", True, (212, 175, 55))
            TextRect = TextSurf.get_rect()
            TextRect.center = 500, 302
            screen.blit(TextSurf, TextRect)
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                if event.type == pygame.MOUSEBUTTONDOWN:
                    mouse_pos = event.pos  # gets mouse position
                    opt = 0
                    if buttonres.collidepoint(mouse_pos):
                        st = 1
                        begin=0
                        i=1

    if st==1 and begin==2:

        screen.fill((85, 52, 43))
        board(playerX, playerY)
        pygame.draw.rect(screen, (212,175,55), (550, 10, 100, 50))
        buttonres = pygame.Rect(550, 10, 200, 100)
        largeText = pygame.font.Font('freesansbold.ttf', 15)
        TextSurf = largeText.render("RESTART", True, (139,69,19))
        TextRect = TextSurf.get_rect()
        TextRect.center = 600, 40
        screen.blit(TextSurf, TextRect)
        #screen.draw.text("Drop shadow", (640, 110), shadow=(2, 2), scolor="#202020")
        v=66
        button1 = pygame.Rect(v, 383, 119, 119)
        v+=125
        button2 = pygame.Rect(v, 383, 119, 119)
        v+=125
        button3 = pygame.Rect(v, 383, 119, 119)
        v+=125
        button4 = pygame.Rect(v, 383, 119, 119)
        v += 125
        button5 = pygame.Rect(v, 383, 119, 119)
        v += 125
        button6 = pygame.Rect(v, 383, 119, 119)
        v += 125
        button7 = pygame.Rect(v, 383, 119, 119)
        button8 = pygame.Rect(v, 133, 119, 119)
        v-=125
        button9 = pygame.Rect(v, 133, 119, 119)
        v -= 125
        button10 = pygame.Rect(v, 133, 119, 119)
        v -= 125
        button11= pygame.Rect(v , 133, 119, 119)
        v -= 125
        button12 = pygame.Rect(v , 133, 119, 119)
        v -= 125
        button13 = pygame.Rect(v , 133, 119, 119)
        v -= 125
        button14 = pygame.Rect(v , 133, 119, 119)
        display()
        largeText = pygame.font.Font('freesansbold.ttf', 15)
        TextSurf = largeText.render("Player 1 score:", True, (255, 0, 0))
        TextRect = TextSurf.get_rect()
        TextRect.center = 120, 20
        screen.blit(TextSurf, TextRect)
        largeText = pygame.font.Font('freesansbold.ttf', 15)
        TextSurf = largeText.render(str(player1count), True, (255, 0, 0))
        TextRect = TextSurf.get_rect()
        TextRect.center = 120, 40
        screen.blit(TextSurf, TextRect)
        largeText = pygame.font.Font('freesansbold.ttf', 15)
        TextSurf = largeText.render(str(player2count), True, (255, 0, 0))
        TextRect = TextSurf.get_rect()
        TextRect.center = 895, 40
        screen.blit(TextSurf, TextRect)
        largeText = pygame.font.Font('freesansbold.ttf', 15)
        TextSurf = largeText.render("Player 2 score", True, (255, 0, 0))
        TextRect = TextSurf.get_rect()
        TextRect.center = 895, 20
        screen.blit(TextSurf, TextRect)

        largeText = pygame.font.Font('freesansbold.ttf', 15)
        TextSurf = largeText.render("Player:", True, (255, 0, 0))
        TextRect = TextSurf.get_rect()
        TextRect.center = 500, 20
        screen.blit(TextSurf, TextRect)
        largeText = pygame.font.Font('freesansbold.ttf', 15)
        TextSurf = largeText.render(str(i), True, (255, 0, 0))
        TextRect = TextSurf.get_rect()
        TextRect.center = 500, 40
        screen.blit(TextSurf, TextRect)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.MOUSEBUTTONDOWN:
                mouse_pos = event.pos  # gets mouse position
                opt=0
                if button1.collidepoint(mouse_pos):
                    # prints current location of mouse
                    print('1:button was pressed at {0}'.format(mouse_pos))
                    opt = 1
                elif button2.collidepoint(mouse_pos):
                    print('2:button was pressed at {0}'.format(mouse_pos))
                    opt = 2
                elif button3.collidepoint(mouse_pos):
                    print('3:button was pressed at {0}'.format(mouse_pos))
                    opt = 3
                elif button4.collidepoint(mouse_pos):
                    print('4:button was pressed at {0}'.format(mouse_pos))
                    opt = 4
                elif button5.collidepoint(mouse_pos):
                    print('5:button was pressed at {0}'.format(mouse_pos))
                    opt = 5
                elif button6.collidepoint(mouse_pos):
                    print('6:button was pressed at {0}'.format(mouse_pos))
                    opt = 6
                elif button7.collidepoint(mouse_pos):
                    print('7:button was pressed at {0}'.format(mouse_pos))
                    opt = 7
                elif button8.collidepoint(mouse_pos):
                    print('8:button was pressed at {0}'.format(mouse_pos))
                    opt = 8
                elif button9.collidepoint(mouse_pos):
                    print('9:button was pressed at {0}'.format(mouse_pos))
                    opt = 9
                elif button10.collidepoint(mouse_pos):
                    print('10:button was pressed at {0}'.format(mouse_pos))
                    opt = 10
                elif button11.collidepoint(mouse_pos):
                    print('11:button was pressed at {0}'.format(mouse_pos))
                    opt = 11
                elif button12.collidepoint(mouse_pos):
                    print('12:button was pressed at {0}'.format(mouse_pos))
                    opt = 12
                elif button13.collidepoint(mouse_pos):
                    print('13:button was pressed at {0}'.format(mouse_pos))
                    opt = 13
                elif button14.collidepoint(mouse_pos):
                    print('14:button was pressed at {0}'.format(mouse_pos))
                    opt = 14
                elif buttonres.collidepoint(mouse_pos):
                    begin=0
                    i=1
                if opt!=0:
                    start(i, int(opt))

                    check = ck()
                    if check==1 or check==2:
                        clear()
                        begin=1

                    if i==1:
                        i+=1
                    else:
                        i-=1


                # checks if mouse position is over the button


      # draw button
    pygame.display.update()