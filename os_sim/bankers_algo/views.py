from django.http import HttpResponse

def index(request):
    	return HttpResponse("<h1>Bankers Algorithm</h1>")
