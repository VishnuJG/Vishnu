import pyautogui
import webbrowser,time
webbrowser.open("https://web.whatsapp.com/")
time.sleep(7)
pyautogui.click(700,700)
pyautogui.hotkey('alt','\t')
time.sleep(2)
pyautogui.click(700,700)
imp=input("Enter name of the user:")
pyautogui.hotkey('alt','\t')
time.sleep(2)
coords=pyautogui.locateOnScreen("D:\\PES\\python\\write whatsapp msg\\start.png",grayscale=False,confidence=0.5)
rods=pyautogui.center((int(coords[0]),int(coords[1]),int(coords[2]),int(coords[3])))
pyautogui.click(int(rods[0]),int(rods[1]))
pyautogui.typewrite(imp)
time.sleep(2)
pyautogui.moveRel(0,200,duration=0.2)
pyautogui.click()
pyautogui.hotkey('alt','\t')
opt=input("Enter type to type the message\nEnter talk to send a voice message\n")

if opt=='type':
    txte=input("Enter message to convey:")
    pyautogui.hotkey('alt','\t')
    time.sleep(2)
    coords=pyautogui.locateOnScreen("D:\\PES\\python\\write whatsapp msg\\type.png",grayscale=False,confidence=0.5)
    rods=pyautogui.center((int(coords[0]),int(coords[1]),int(coords[2]),int(coords[3])))
    pyautogui.click(int(rods[0])+100,int(rods[1]))
    pyautogui.typewrite(txte)
    pyautogui.press('enter')
    time.sleep(2)
    pyautogui.hotkey('alt','\t')
elif opt=='talk':
    timee=input("Enter the duration of the voice message:")
    pyautogui.hotkey('alt','\t')
    time.sleep(2)
    coords=pyautogui.locateOnScreen("D:\\PES\\python\\write whatsapp msg\\mic.png",grayscale=False,confidence=0.5)
    rods=pyautogui.center((int(coords[0]),int(coords[1]),int(coords[2]),int(coords[3])))
    pyautogui.click(int(rods[0])+580,int(rods[1]),duration=0.2)
    time.sleep(int(timee)+1)
    pyautogui.click()
    time.sleep(2)
    pyautogui.hotkey('alt','\t')


