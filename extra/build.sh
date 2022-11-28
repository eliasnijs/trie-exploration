#!/bin/sh

groff -ms -s -e -t -p -U -R report.ms -T ps > report.ps
ps2pdf report.ps > report.pdf
