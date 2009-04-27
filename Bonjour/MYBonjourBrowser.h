//
//  MYBonjourBrowser.h
//  MYNetwork
//
//  Created by Jens Alfke on 1/22/08.
//  Copyright 2008 Jens Alfke. All rights reserved.
//

#import "MYDNSService.h"


/** Searches for Bonjour services of a specific type. */
@interface MYBonjourBrowser : MYDNSService
{
    @private
    NSString *_serviceType;
    BOOL _browsing;
    Class _serviceClass;
    NSMutableSet *_services, *_addServices, *_rmvServices;
}

/** Initializes a new BonjourBrowser.
    Call -start to begin browsing.
    @param serviceType  The name of the service type to look for, e.g. "_http._tcp". */
- (id) initWithServiceType: (NSString*)serviceType;

/** Is the browser currently browsing? */
@property (readonly) BOOL browsing;

/** The set of currently found services. These are instances of the serviceClass,
    which is BonjourService by default.
    This is KV-observable. */
@property (readonly) NSSet *services;

/** The class of objects to create to represent services.
    The default value is [BonjourService class]; you can change this, but only
    to a subclass of that. */
@property Class serviceClass;

@end