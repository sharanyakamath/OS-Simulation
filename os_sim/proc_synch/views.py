from django.http import HttpResponse

# Create your views here.
def index1(request):
	return HttpResponse("<h1>Process Synchronisation</h1> <h3>Algorithms:</h3> <ul> <li><a href=http://127.0.0.1:8000/proc_synch/dining_philosopher>Dining Philosopher </a></li> <li><a href=http://127.0.0.1:8000/proc_synch/producer_consumer>Producer Consumer </a></li> <li><a href=http://127.0.0.1:8000/proc_synch/reader_writer>Reader Writer </a></li></ul>")

def index2(request):
	return HttpResponse("<h1>Dining Philosopher</h1>")

def index3(request):
	return HttpResponse("<h1>Producer Consumer</h1>")

def index4(request):
	return HttpResponse("<h1>Reader Writer</h1>")