from selenium import webdriver
from datetime import date
import time
import secrets

#setup web environment
web=webdriver.Chrome()
web.get('https://docs.google.com/forms/d/e/1FAIpQLSfyJW9O5fkBUaniPnbty-9L91J-Hge6-xlzNXwSsh9nYqzL4w/viewform?usp=sf_link')

#load the url before trying to automate
time.sleep(0.5)

#random selection
options=['Wind Ensemble', 'Concert Band', 'Jazz']
w1=secrets.choice(options)
options.remove(w1)
w2=secrets.choice(options)

#easy typing
def find(s):
    return web.find_element_by_xpath(s)

#date
today=date.today()
today=today.strftime('%m%d%Y')
print(today)
calendar=find('//*[@id="mG61Hd"]/div[2]/div/div[2]/div[1]/div/div/div[2]/div/div/div[2]/div[1]/div/div[1]/input')
calendar.send_keys(today)

#q1
work=find('//*[@id="mG61Hd"]/div[2]/div/div[2]/div[2]/div/div/div[2]/div/div[1]/div/div[1]/input')
work.send_keys(w1)

#q2
longtones=find('//*[@id="i15"]')
scales=find('//*[@id="i18"]')
repetoire=find('//*[@id="i21"]')
etude=find('//*[@id="i24"]')
rec=find('//*[@id="i27"]')
metr=find('//*[@id="i30"]')
#fixed vals
longtones.click()
scales.click()
repetoire.click()
rec.click()
#variation
if w1=='Jazz' or w1=='Wind Ensemble':
    etude.click()

if secrets.randbelow(3)==0:
    metr.click()

#q3
slow=find('//*[@id="i47"]')
chunk=find('//*[@id="i50"]')
pencil=find('//*[@id="i53"]')
rep=find('//*[@id="i56"]')
#fixed vals
chunk.click()
rep.click()
if w1=='Wind Ensemble':
    slow.click()
    pencil.click()
elif w1=='Jazz':
    pencil.click()

#q4
work=find('//*[@id="mG61Hd"]/div[2]/div/div[2]/div[5]/div/div/div[2]/div/div[1]/div/div[1]/input')
work.send_keys(w2)

#submit
submit=find('//*[@id="mG61Hd"]/div[2]/div/div[3]/div[1]/div/div/span')
submit.click()
