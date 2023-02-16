import requests
from bs4 import BeautifulSoup


# Make a request to the website
url = "https://finispia.com"
response = requests.get(url)



# Check if the request was successful
if response.status_code == 200:
    # Parse the HTML content of the page
    soup = BeautifulSoup(response.content, "html.parser")
    links = soup.select("a")

for link in links:
    print( link.get("href"))

# Extract data from the HTML
title = soup.find("title").text
header = soup.find("header").text
print("Title:", title)
print("Header:", header)

response = requests.get(url)
<div class="cmpState" style="background: rgb(0, 184, 113);">Halal</div>


querystring = {"symbol":"FB","exchange":"NASDAQ"}

headers = {
	"X-RapidAPI-Key": "0d7656cb3cmshb589f4fd175f534p15e158jsn1d902714f7e7",
	"X-RapidAPI-Host": "finispia2.p.rapidapi.com"
}

response = requests.request("GET", url + "/company/compliance", headers=headers, params=querystring)

print(response.text)

search_term = "APPL"
search_url = url + "/api/v2/company/searchList/{}".format(search_term)
# Make a GET request to the search URL
response = requests.get(search_url)

# Parse the HTML content of the response
soup = BeautifulSoup(response.content, "html.parser")

# Extract the search results from the HTML
results = soup.select(".search-result")
print(results)
for result in results:
    title = result.select(".result-title")[0].text
    description = result.select(".result-description")[0].text
    print("Title:", title)
    print("Description:", description)