from bs4 import BeautifulSoup 
import requests 
import pandas as pd
import yfinance as yf



def get_stock_price(ticker):
    data = yf.download(ticker)
    return pd.DataFrame(data)

response = requests.get("https://www.marketbeat.com/stocks/AAPL/")
soup = BeautifulSoup(response.content, "html.parser")
print(soup)
dividend_yield = soup.find("span", {"class": "dividens"})
print(dividend_yield)