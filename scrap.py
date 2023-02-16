rl = 'https://www.investing.com'

###################################
import requests

req = requests.get(url)
print(req)  # <Response [403]>

###################################
import cloudscraper

scraper = cloudscraper.create_scraper()  # returns a CloudScraper instance

ret = scraper.get(url)
print(ret) # <Response [200]>

url = "http://api.scraperlink.com/investpy/?email=ait_lhaj92@live.fr&type=historical_data&product=stocks&country=united%20states&symbol=MDT&from_date=11/14/2022&to_date=11/15/2022"
#response = requests.get(url).content
response = requests.get(url)
print(response)
resp_dict = response.json()

df = pd.DataFrame(resp_dict.get('data'))

print(df['last_close'])