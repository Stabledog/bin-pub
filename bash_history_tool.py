#!/usr/bin/env python3

# Helper for bash history maintenance

from typing import OrderedDict, Callable
from collections import OrderedDict


class Command:
    def __init__(self, command_text: str, timestamp: int = 0):
        self.command_text = command_text
        self.timestamp = timestamp


def condense_bash_history(
    event_stream: Callable, cache: OrderedDict = None
) -> OrderedDict:
    """Read events from event_stream.  Events should be in reverse-time order.
    First we distinguish timestamps from commands.
    If event is a command, and does not contain a '#', it is discarded.
    If the command is already present in cache, then it is discarded.
    Remaining commands are added to the cache.

    If event is a timestamp, and the most-recently-added-command lacks a timestamp,
    the timestamp is added to that event.

    Returns: cache in reverse-time order without duplicates


    """
