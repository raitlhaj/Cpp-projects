import requests

url = "https://finispia-usa-with-company-details.p.rapidapi.com/company/aaoifi/detail"

querystring = {"symbol":"FB"}

headers = {
	"X-RapidAPI-Key": "0d7656cb3cmshb589f4fd175f534p15e158jsn1d902714f7e7",
	"X-RapidAPI-Host": "finispia-usa-with-company-details.p.rapidapi.com"
}

response = requests.request("GET", url, headers=headers, params=querystring)

print(response.text)