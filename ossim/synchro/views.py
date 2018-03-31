from django.shortcuts import render

# Create your views here.
from . models import SynchroAlg

def SocketIndex(request):
    return render(request,'synchro/SocketIndex.html')

def Socket(request):
    return render(request,'synchro/Socket.html')

def Bind(request):
    return render(request,'synchro/Bind.html')

def Listen(request):
    return render(request,'synchro/Listen.html')

def Connect(request):
    return render(request,'synchro/Connect.html')

def Accept(request):
    return render(request,'synchro/Accept.html')

def Send(request):
    return render(request,'synchro/Send.html')

def Receive(request):
    return render(request,'synchro/Receive.html')

def Close(request):
    return render(request,'synchro/Close.html')

def SocketIndex2(request):
    return render(request,'synchro/SocketIndex2.html')

def Socket2(request):
    return render(request,'synchro/Socket2.html')

def Bind2(request):
    return render(request,'synchro/Bind2.html')

def Send2(request):
    return render(request,'synchro/Send2.html')

def Receive2(request):
    return render(request,'synchro/Receive2.html')

def Close2(request):
    return render(request,'synchro/Close2.html')
def semaphores(request):
    algos = SynchroAlg.objects.filter(demourl="sem")
    context = {'algos': algos}
    return render(request, 'synchro/semaphores_index.html',context = context)

def socket(request):
    algos = SynchroAlg.objects.filter(demourl="tcp")
    context = {'algos': algos}
    return render(request, 'synchro/socket_index.html',context = context)

def deadlocks(request):
    return render(request,'synchro/bankerindex.html')

def bankalgo(request):
    return render(request, 'synchro/bankers.html')

def sem_demo(request,pk):
    if(pk=='1'):
        return render(request, 'synchro/prodcon2.html')
    if(pk=='2'):
        return render(request, 'synchro/readerwriter.html')
    if(pk=='3'):
        return render(request, 'synchro/diningphils.html')
    if(pk=='4'):
        return render(request, 'synchro/sleepingbarber.html')

def socket_demo(request,pk):
    if(pk=='1'):
        return render(request, 'synchro/TCP.html')
    if(pk=='2'):
        return render(request, 'synchro/UDP.html')
