# pip3 install robobrowser
from robobrowser import RoboBrowser

browser = RoboBrowser()
browser.open('https://cdn.hackerrank.com/hackerrank/static/contests/capture-the-flag/infinite/qds.html')
history = ['https://cdn.hackerrank.com/hackerrank/static/contests/capture-the-flag/infinite/qds.html']
font = browser.find_all('font')
links = browser.get_links()

while len(font) < 50000 and len(links) > 0:
    for link in links:
        if link not in history:
            browser.follow_link(link)
            font.extend(browser.find_all())
            links.extend(browser.get_links())
            history.append(link)
        links.remove(link)

print(font)
