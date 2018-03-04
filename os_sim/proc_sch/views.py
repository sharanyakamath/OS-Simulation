from django.http import HttpResponse

# Create your views here.
def index(request):
	return HttpResponse("<h1>Process Scheduling</h1> <h3>Algorithms:</h3> <ul> <li>FCFS</li> <li>SJF non-preemptive</li> <li>SJF preemptive</li> <li>Priority non-preemptive</li> <li>Priority preemptive</li> <li>Round-Robin</li>")