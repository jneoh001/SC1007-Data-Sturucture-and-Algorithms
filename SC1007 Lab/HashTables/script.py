from selenium import webdriver
import time

browser = webdriver.Chrome()
browser.get('https://forms.gle/XKXCjQ5qPJ46uzX6A')

option1 = browser.find_element_by_xpath('//*[@id="i11"]/div[3]/div')
option1.click()

option2 = browser.find_element_by_xpath('//*[@id="i24"]/div[3]/div')
option2.click()