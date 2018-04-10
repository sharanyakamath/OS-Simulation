from django.conf.urls import url,include
from django.contrib import admin
from . import views

app_name = 'rtos'
urlpatterns =[
    url(r'^$', views.home, name='index'),
    url(r'^rms/$', views.rms, name='rms'),
    url(r'^wiki/$', views.wiki, name='wiki'),
]
