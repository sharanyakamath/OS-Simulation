from django.shortcuts import get_object_or_404, render, redirect
from django.http import HttpResponseRedirect,HttpResponse
#from django.core.urlresolvers import reverse


def index(request):
    return render(request, 'ossim/index.html')

def matindex(request):
    return render(request, 'mat/mainindex.html')
