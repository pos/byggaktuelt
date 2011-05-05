/*buildcalculator.js*/

// JavaScript Document
$(document).ready(function() {

    $('#loadingDiv')
    .hide()  // hide it initially
    .ajaxStart(function() {
        $(this).show().html('Beräknar vänta..');
        $('#buildcalculator_adv_submit').attr('disabled', true);
    })
    .ajaxStop(function() {
        $(this).hide();
        $('#buildcalculator_adv_submit').attr('disabled', false );
    });

    $('#buildcalculator_adv_submit').click(function() {

      var buildtypeValue = parseFloat( $("#edit-buildtypeadv").val().replace(",", ".") );
      var province = parseFloat( $("#edit-provinceadv").val().replace(",", ".") );
      var meter = parseFloat( $("#buildcalculator_adv-meter").val() );

      $.ajax({
          type: 'POST',//!!!! Obs on server use url '/calculator' only !!!!!!
          url: Drupal.settings.basePath +'buildcalculator_adv/calculator', // Which url should be handle the ajax request. This is the url defined in the <a> html tag
          success: updatehtml,// The js function that will be called upon success request
          dataType: 'json', //define the type of data that is going to get back from the server
          data: 'buildtypeValue='+buildtypeValue +'&province='+province+'&meter='+meter //Pass a key/value pair
      });

     
        return false;
    });
});

function updatehtml(data){
  var result = eval( data );
  
  $('#totalt_huskostnader').html(result.data.housesum);
  $('#gj_ventilasjonskostnad').html(result.data.gj.vent);
  $('#gj_rorkostnad').html(result.data.gj.ror);
  $('#gj_elkostnad').html(result.data.gj.el);

  $('#paslag').html(result.data.houseaddons);

  $('#honorarer').html(result.data.add.honorarer);
  $('#adm_og_byggeledelse').html(result.data.add.adm);
  $('#finansieringskostnader').html(result.data.add.fin);
  $('#tomtekostnader').html( result.data.add.tomt );
  $('#andre_kostnader').html( result.data.add.andre );
  $('#offentlige_avgifter').html( result.data.add.offent );

  $('#totalkostnad').html( result.data.total );
  
}

