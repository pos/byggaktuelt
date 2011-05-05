/*buildcalculator.js*/

// JavaScript Document
$(document).ready(function() {
	
    $('#buildcalculator-submit').click(function() {
       
       var buildtypeValue = parseFloat($("#edit-buildtype").val() );

       var meter = parseFloat( $("#buildcalculator-meter").val());
       var sum = buildtypeValue * meter;
       sum = addCommas(sum);
       $('#buildcalculator-status').html('<strong>Prisanslag (kr eks mva) ' + sum + ' Nkr</strong>');
       
        return false;
    });
});

function addCommas(nStr)
{
	nStr += '';
	x = nStr.split('.');
	x1 = x[0];
	x2 = x.length > 1 ? '.' + x[1] : '';
	var rgx = /(\d+)(\d{3})/;
	while (rgx.test(x1)) {
		x1 = x1.replace(rgx, '$1' + ',' + '$2');
	}
	return x1 + x2;
}


