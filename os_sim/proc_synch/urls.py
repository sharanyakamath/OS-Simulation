from django.conf.urls import url
from . import views
urlpatterns = [
    url(r'^$', views.index1,name='index1'),
    url(r'^dining_philosopher/',views.index2,name='index2'),
    url(r'^producer_consumer/',views.index3,name='index3'),
    url(r'^reader_writer/',views.index4,name='index4'),
]