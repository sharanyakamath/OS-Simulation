

# Create your views here.
from django.shortcuts import render
from . import executer
from django.http import JsonResponse
from django.views.decorators.csrf import csrf_protect
# Create your views here.


def home(request):
    return render(request,'rtos/rtos_index.html')


@csrf_protect
def rms(request):
    print ("hello")
    if request.method == "GET":
        print ("hello_get")
        inp = request.GET.get('input', None)
        if inp == None:
            return render(request, 'rtos/rtos_rms.html')
        print (inp)
        out = executer.execute('rtos/RTOS/rate_monotonic', inp)
        print (out)
        data = {
            'output' : out
        }
        print (data)
        return JsonResponse(data)
    else:
        print ("hello_else")
        return render(request, 'rtos/rtos_rms.html')
def wiki(request):
    return render(request,'rtos/rtos_wiki.html')
