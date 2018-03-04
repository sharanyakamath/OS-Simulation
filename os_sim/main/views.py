from django.http import HttpResponse

# Create your views here.
def ind(request):
	return HttpResponse("<body> <h1> OS Simulation</h1> <h3>Topics:</h3> <ul> <li>System Calls</li> <li><a href=http://127.0.0.1:8000/proc_sch>Process Scheduling </a> </li> <li>Process Synchronisation</li> <li>Socket Programming</li> <li>Banker's Algorithm</li> <li>File Management</li> </ul> <br> <a href=http://127.0.0.1:8000/admin>Click here for simulation</a> </body>")